/*
 *  emulator main execution loop
 *
 *  Copyright (c) 2003-2005 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
#include "config.h"
#include "cpu.h"
#include "trace.h"
#include "disas/disas.h"
#include "tcg.h"
#include "qemu/atomic.h"
#include "sysemu/qtest.h"
#include "qemu/timer.h"
#include "exec/address-spaces.h"
#include "exec/memory-internal.h"
#include "qemu/rcu.h"
#include "afl/afl-qemu-cpu-inl.h"
// Bo: check whether address range is valid
#include "hw/arm/cortexm-mcu.h"
#include "peri-mod/peri-mod.h"
#include "peri-mod/interrupt.h"

/* -icount align implementation. */

typedef struct SyncClocks {
    int64_t diff_clk;
    int64_t last_cpu_icount;
    int64_t realtime_clock;
} SyncClocks;

#if !defined(CONFIG_USER_ONLY)
/* Allow the guest to have a max 3ms advance.
 * The difference between the 2 clocks could therefore
 * oscillate around 0.
 */
#define VM_CLOCK_ADVANCE 3000000
#define THRESHOLD_REDUCE 1.5
#define MAX_DELAY_PRINT_RATE 2000000000LL
#define MAX_NB_PRINTS 100

static void align_clocks(SyncClocks *sc, const CPUState *cpu)
{
    int64_t cpu_icount;

    if (!icount_align_option) {
        return;
    }

    cpu_icount = cpu->icount_extra + cpu->icount_decr.u16.low;
    sc->diff_clk += cpu_icount_to_ns(sc->last_cpu_icount - cpu_icount);
    sc->last_cpu_icount = cpu_icount;

    if (sc->diff_clk > VM_CLOCK_ADVANCE) {
#ifndef _WIN32
        struct timespec sleep_delay, rem_delay;
        sleep_delay.tv_sec = sc->diff_clk / 1000000000LL;
        sleep_delay.tv_nsec = sc->diff_clk % 1000000000LL;
        if (nanosleep(&sleep_delay, &rem_delay) < 0) {
            sc->diff_clk = rem_delay.tv_sec * 1000000000LL + rem_delay.tv_nsec;
        } else {
            sc->diff_clk = 0;
        }
#else
        Sleep(sc->diff_clk / SCALE_MS);
        sc->diff_clk = 0;
#endif
    }
}

static void print_delay(const SyncClocks *sc)
{
    static float threshold_delay;
    static int64_t last_realtime_clock;
    static int nb_prints;

    if (icount_align_option &&
        sc->realtime_clock - last_realtime_clock >= MAX_DELAY_PRINT_RATE &&
        nb_prints < MAX_NB_PRINTS) {
        if ((-sc->diff_clk / (float)1000000000LL > threshold_delay) ||
            (-sc->diff_clk / (float)1000000000LL <
             (threshold_delay - THRESHOLD_REDUCE))) {
            threshold_delay = (-sc->diff_clk / 1000000000LL) + 1;
            printf("Warning: The guest is now late by %.1f to %.1f seconds\n",
                   threshold_delay - 1,
                   threshold_delay);
            nb_prints++;
            last_realtime_clock = sc->realtime_clock;
        }
    }
}

static void init_delay_params(SyncClocks *sc,
                              const CPUState *cpu)
{
    if (!icount_align_option) {
        return;
    }
    sc->realtime_clock = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL_RT);
    sc->diff_clk = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL) - sc->realtime_clock;
    sc->last_cpu_icount = cpu->icount_extra + cpu->icount_decr.u16.low;
    if (sc->diff_clk < max_delay) {
        max_delay = sc->diff_clk;
    }
    if (sc->diff_clk > max_advance) {
        max_advance = sc->diff_clk;
    }

    /* Print every 2s max if the guest is late. We limit the number
       of printed messages to NB_PRINT_MAX(currently 100) */
    print_delay(sc);
}
#else
static void align_clocks(SyncClocks *sc, const CPUState *cpu)
{
}

static void init_delay_params(SyncClocks *sc, const CPUState *cpu)
{
}
#endif /* CONFIG USER ONLY */

void cpu_loop_exit(CPUState *cpu)
{
    cpu->current_tb = NULL;
    siglongjmp(cpu->jmp_env, 1);
}

/* exit the current TB from a signal handler. The host registers are
   restored in a state compatible with the CPU emulator
 */
#if defined(CONFIG_SOFTMMU)
void cpu_resume_from_signal(CPUState *cpu, void *puc)
{
    /* XXX: restore cpu registers saved in host registers */

    cpu->exception_index = -1;
    siglongjmp(cpu->jmp_env, 1);
}

void cpu_reload_memory_map(CPUState *cpu)
{
    AddressSpaceDispatch *d;

    if (qemu_in_vcpu_thread()) {
        /* Do not let the guest prolong the critical section as much as it
         * as it desires.
         *
         * Currently, this is prevented by the I/O thread's periodinc kicking
         * of the VCPU thread (iothread_requesting_mutex, qemu_cpu_kick_thread)
         * but this will go away once TCG's execution moves out of the global
         * mutex.
         *
         * This pair matches cpu_exec's rcu_read_lock()/rcu_read_unlock(), which
         * only protects cpu->as->dispatch.  Since we reload it below, we can
         * split the critical section.
         */
        rcu_read_unlock();
        rcu_read_lock();
    }

    /* The CPU and TLB are protected by the iothread lock.  */
    d = atomic_rcu_read(&cpu->as->dispatch);
    cpu->memory_dispatch = d;
    tlb_flush(cpu, 1);
}
#endif

volatile unsigned int bbl_cnt = 0;
volatile unsigned int target_bbl_cnt = 0;
volatile unsigned int bbl_cnt_last_me = 0;
volatile int expl_started = 0;
volatile int int_round = 0;
volatile unsigned int bbl_exec_times = 0;
volatile unsigned int last_bbl_exec = 0;
volatile unsigned int run_main_times = 0; // times that reach the end of main
#define MAX_ADDRESS_NUM 0x10

/* Execute a TB, and fix up the CPU state afterwards if necessary */
static inline tcg_target_ulong cpu_tb_exec(target_ulong pc, CPUState *cpu, uint8_t *tb_ptr, uint16_t size)
{
    CPUArchState *env = cpu->env_ptr;
    uintptr_t next_tb;
#if defined(DEBUG_DISAS)
    if (qemu_loglevel_mask(CPU_LOG_TB_CPU)) {
#if defined(TARGET_I386)
        log_cpu_state(cpu, CPU_DUMP_CCOP);
#elif defined(TARGET_M68K)
        /* ??? Should not modify env state for dumping.  */
        cpu_m68k_flush_flags(env, env->cc_op);
        env->cc_op = CC_OP_FLAGS;
        env->sr = (env->sr & 0xffe0) | env->cc_dest | (env->cc_x << 4);
        log_cpu_state(cpu, 0);
#else
        log_cpu_state(cpu, 0);
#endif
    }
#endif /* DEBUG_DISAS */

    cpu->can_do_io = 0;
    next_tb = tcg_qemu_tb_exec(env, tb_ptr);
    cpu->can_do_io = 1;
    trace_exec_tb_exit((void *) (next_tb & ~TB_EXIT_MASK),
                       next_tb & TB_EXIT_MASK);

    if ((next_tb & TB_EXIT_MASK) > TB_EXIT_IDX1) {
        /* We didn't start executing this TB (eg because the instruction
         * counter hit zero); we must restore the guest PC to the address
         * of the start of the TB.
         */
        CPUClass *cc = CPU_GET_CLASS(cpu);
        TranslationBlock *tb = (TranslationBlock *)(next_tb & ~TB_EXIT_MASK);
        if (cc->synchronize_from_tb) {
            cc->synchronize_from_tb(cpu, tb);
        } else {
            assert(cc->set_pc);
            cc->set_pc(cpu, tb->pc);
        }
    } else {
      /* we executed it, trace it */
      AFL_QEMU_CPU_SNIPPET2(env, pc, size);
	  //printf("func=%s s=%#x e=%#x stage=%d bbl=%d\n", lookup_symbol(pc), cur_bbl_s, cur_bbl_e, pm_stage, bbl_cnt);
#define __OPEN_UNIT_TEST__
#ifdef __OPEN_UNIT_TEST__
	 if(run_from_afl && pm_stage == FUZZING && 
	 	pc == main_eaddr && pm_interrupt->arr_size == 0 &&
		has_seed_consume) {
	  	exit(0);
	 }
	
#endif

      bbl_cnt++;

#ifdef __OPEN_MULTI_STATUS__
	  //check hang in while
	  if(pc == last_bbl_exec && size < 5) {
	    bbl_exec_times++;
	  	if(pc != main_eaddr) {
		  // when detect hang in SR_R_ID stage we try to rollback
		  // keep bbl_exec_times less than FUZZING_INT_FREQ
		  if(pm_stage == SR_R_ID && last_CR_SR_peri_addr != 0 &&
		      bbl_exec_times > 5 && bbl_cnt - last_CR_SR_bbl_cnt < 20) {
		    // caused by CR_SR 
		    pm_Peripheral *peri = get_peri(last_CR_SR_peri_addr);
		    unsigned int reg_idx = (last_CR_SR_peri_addr % PM_PERI_ADDR_RANGE) / peri->reg_size;
		    pm_MMIORegister *reg = &peri->regs[reg_idx];
		    reg->result_hang_in_while = true;
			peri->hang_in_while_flag = true;
		    stage_term_reg_idx[cur_bbl_SR_r_num] = reg_idx;
		    stage_term_peri_ba[cur_bbl_SR_r_num] = peri->base_addr;
		    cur_bbl_SR_r_num++;
		    cur_bbl_s = last_CR_SR_bbl_s;
		    cur_bbl_e = last_CR_SR_bbl_e;
		    bbl_cnt = last_CR_SR_bbl_cnt;
		    CR_SR_r_idx_in_bbl = peri->regs_back[reg_idx].hang_r_idx_in_bbl;
		  } 

		  // when not in Fuzzing with pre test
		  if(!run_from_afl && pm_stage == FUZZING && bbl_exec_times > 10000) {
		    int id = pm_interrupt->cur_int == 0 ? pm_interrupt->arr_size - 1 : pm_interrupt->cur_int - 1;
		    if(is_int_triggered && pm_interrupt->arr[id].int_num != 15) {
		  	  is_int_triggered = false;
		  	  pm_interrupt->arr[id].result_hang = true;
		  	  printf("Error interrupt is detected, try to update model\n");
		  	  doneWork(PM_UNCAT_REG);
		    }
		  }

		  // result hang when using other status
		  if(run_from_afl && pm_stage == FUZZING && 
		  	bbl_exec_times > 10) {
			exit(0);
		  }
		  // when in SR_R_EXPLORE, we print trace to log file in order to
          // identifty which the explore value result hang
           if (pm_stage == SR_R_EXPLORE && bbl_exec_times > 5000) {
           		fprintf(trace_f, "BBL (0x%x, 0x%x) [%s]\n", pc, pc+size,
              		lookup_symbol(pc));
		  	}
		} 

	  } else {
		bbl_exec_times = 0;
		last_bbl_exec = pc;
	  }


#endif

      // Handle fuzzing specific operations first to speed up it
      if ((pm_stage == FUZZING || 
        (pm_stage == SR_R_ID || pm_stage == SR_R_EXPLORE) && 
        aflFile && bbl_cnt <= replay_bbl_cnt)) {
        // During fuzzing or replay process in ME

        // interrupt firing: one interrupt/FUZZING_INT_FREQ executed
        // after startForkserver is invoked
        if (afl_startfs_invoked) {
          if (bbl_cnt % FUZZING_INT_FREQ == 0)
            pm_fire_interrupt();
        }

        // unmodelled SR read detected
        // stage Fuzzing handles in that SR_r and won't reach here
        // current impl is for on-demand ME only: CR_ins del all SMR
        // and during replay we need to do SMR
        // TODO make impl uniform
        if (pm_stage == SR_R_ID && cur_bbl_SR_r_num) {
          sr_func = lookup_symbol(cur_bbl_s);
          // info dumped by pm_dump_model:
          // sr_func, cur_bbl_s, bbl_cnt, cur_bbl_SR_r_num
          // bbl_cnt dumped includes the bbl which SR_r happens
          stage_termination(SR_R_ID);
          if (SR_cat_by_fixup) exit(0x19);
          else exit(0x20);
        }

        // dump trace for coverage calculation in stage FUZZING and 
        // replay process for stage 1. 
        // For stage 2, we only dump trace after expl_started
        if (trace_f && pm_stage != SR_R_EXPLORE)
          fprintf(trace_f, "BBL (0x%x, 0x%x) [%s]\n", pc, pc+size,
            lookup_symbol(pc));

      } else {
        // stage 1/2 && not doing replay

        // must do this before setting expl_started
        if (pm_stage == SR_R_ID || (pm_stage == SR_R_EXPLORE && expl_started))
          fprintf(trace_f, "BBL (0x%x, 0x%x) [%s]\n", pc, pc+size, 
            lookup_symbol(pc));

        if (pm_stage == SR_R_ID && cur_bbl_SR_r_num) {
          sr_func = lookup_symbol(cur_bbl_s);
          // info dumped by pm_dump_model:
          // sr_func, cur_bbl_s, bbl_cnt, cur_bbl_SR_r_num
          // bbl_cnt dumped includes the bbl which SR_r happens
          stage_termination(SR_R_ID);
          if (SR_cat_by_fixup) exit(0x19);
          else exit(0x20);
        }

        if (pm_stage == SR_R_EXPLORE) {
          // expl_started = 1 when bbl that does SR read has been executed
          expl_started = bbl_cnt >= target_bbl_cnt ? 1 : 0;

          // worker cannot run forever
          if (expl_started && (bbl_cnt - target_bbl_cnt > SR_R_WORKER_BBL_CNT_CAP)) {
            // traeat as func_ret
            stage_termination(SR_R_EXPLORE);
            exit(0x21);
          }
        }

        // During ME, fire interrupt every ME_TERM_THRESHOLD BBL.
        // exit after every interrupt is fired INT_ROUND times
        if ((pm_stage == SR_R_ID || pm_stage == SR_R_EXPLORE) && 
          (bbl_cnt - bbl_cnt_last_me) >= ME_TERM_THRESHOLD) {
          if (int_round < INT_ROUND) {
            pm_fire_interrupt();
            bbl_cnt_last_me = bbl_cnt;
          } else if (pm_stage == SR_R_ID) {
            stage_termination(SR_R_ID);
            exit(0x30);
          }
        }
      }
    }

    if ((next_tb & TB_EXIT_MASK) == TB_EXIT_REQUESTED) {
        /* We were asked to stop executing TBs (probably a pending
         * interrupt. We've now stopped, so clear the flag.
         */
        cpu->tcg_exit_req = 0;
    }
    if(afl_wants_cpu_to_stop)
        cpu->exit_request = 1;

    return next_tb;
}

/* Execute the code without caching the generated code. An interpreter
   could be used if available. */
static void cpu_exec_nocache(CPUArchState *env, int max_cycles,
                             TranslationBlock *orig_tb)
{
    CPUState *cpu = ENV_GET_CPU(env);
    TranslationBlock *tb;
    target_ulong pc = orig_tb->pc;
    target_ulong cs_base = orig_tb->cs_base;
    uint64_t flags = orig_tb->flags;

    /* Should never happen.
       We only end up here when an existing TB is too long.  */
    if (max_cycles > CF_COUNT_MASK)
        max_cycles = CF_COUNT_MASK;

    /* tb_gen_code can flush our orig_tb, invalidate it now */
    tb_phys_invalidate(orig_tb, -1);
    tb = tb_gen_code(cpu, pc, cs_base, flags,
                     max_cycles | CF_NOCACHE);
    cpu->current_tb = tb;
    /* execute the generated code */
    trace_exec_tb_nocache(tb, tb->pc);
    cpu_tb_exec(tb->pc, cpu, tb->tc_ptr, tb->size);
    cpu->current_tb = NULL;
    tb_phys_invalidate(tb, -1);
    tb_free(tb);
}

static TranslationBlock *tb_find_slow(CPUArchState *env,
                                      target_ulong pc,
                                      target_ulong cs_base,
                                      uint64_t flags)
{
    CPUState *cpu = ENV_GET_CPU(env);
    TranslationBlock *tb, **ptb1;
    unsigned int h;
    tb_page_addr_t phys_pc, phys_page1;
    target_ulong virt_page2;

    tcg_ctx.tb_ctx.tb_invalidated_flag = 0;

    /* find translated block using physical mappings */
    phys_pc = get_page_addr_code(env, pc);
    phys_page1 = phys_pc & TARGET_PAGE_MASK;
    h = tb_phys_hash_func(phys_pc);
    ptb1 = &tcg_ctx.tb_ctx.tb_phys_hash[h];
    for(;;) {
        tb = *ptb1;
        if (!tb)
            goto not_found;
        if (tb->pc == pc &&
            tb->page_addr[0] == phys_page1 &&
            tb->cs_base == cs_base &&
            tb->flags == flags) {
            /* check next page if needed */
            if (tb->page_addr[1] != -1) {
                tb_page_addr_t phys_page2;

                virt_page2 = (pc & TARGET_PAGE_MASK) +
                    TARGET_PAGE_SIZE;
                phys_page2 = get_page_addr_code(env, virt_page2);
                if (tb->page_addr[1] == phys_page2)
                    goto found;
            } else {
                goto found;
            }
        }
        ptb1 = &tb->phys_hash_next;
    }
 not_found:
   /* if no translated code available, then translate it now */
    tb = tb_gen_code(cpu, pc, cs_base, flags, 0);
    AFL_QEMU_CPU_SNIPPET1;

 found:
 
    /* Move the last found TB to the head of the list */
    if (likely(*ptb1)) {
        *ptb1 = tb->phys_hash_next;
        tb->phys_hash_next = tcg_ctx.tb_ctx.tb_phys_hash[h];
        tcg_ctx.tb_ctx.tb_phys_hash[h] = tb;
    }
    /* we add the TB in the virtual pc hash table */
    cpu->tb_jmp_cache[tb_jmp_cache_hash_func(pc)] = tb;
    return tb;
}

static inline TranslationBlock *tb_find_fast(CPUArchState *env)
{
    CPUState *cpu = ENV_GET_CPU(env);
    TranslationBlock *tb;
    target_ulong cs_base, pc;
    int flags;

    /* we record a subset of the CPU state. It will
       always be the same before a given translated block
       is executed. */
    cpu_get_tb_cpu_state(env, &pc, &cs_base, &flags);
	
    
	tb = cpu->tb_jmp_cache[tb_jmp_cache_hash_func(pc)];
    if (unlikely(!tb || tb->pc != pc || tb->cs_base != cs_base ||
                 tb->flags != flags)) {
        tb = tb_find_slow(env, pc, cs_base, flags);
    }
    return tb;
}

static void cpu_handle_debug_exception(CPUArchState *env)
{
    CPUState *cpu = ENV_GET_CPU(env);
    CPUClass *cc = CPU_GET_CLASS(cpu);
    CPUWatchpoint *wp;

    if (!cpu->watchpoint_hit) {
        QTAILQ_FOREACH(wp, &cpu->watchpoints, entry) {
            wp->flags &= ~BP_WATCHPOINT_HIT;
        }
    }

    cc->debug_excp_handler(cpu);
}

/* main execution loop */

volatile sig_atomic_t exit_request;

int cpu_exec(CPUArchState *env)
{
    CPUState *cpu = ENV_GET_CPU(env);
    CPUClass *cc = CPU_GET_CLASS(cpu);
#ifdef TARGET_I386
    X86CPU *x86_cpu = X86_CPU(cpu);
#endif
    int ret, interrupt_request;
    TranslationBlock *tb;
    uint8_t *tc_ptr;
    // last executed tb, used to check exec ret_val & for bbl chainin
    uintptr_t next_tb;
    SyncClocks sc;

    /* This must be volatile so it is not trashed by longjmp() */
    volatile bool have_tb_lock = false;

    if (cpu->halted) {
        if (!cpu_has_work(cpu)) {
            return EXCP_HALTED;
        }

        cpu->halted = 0;
    }

    current_cpu = cpu;

    /* As long as current_cpu is null, up to the assignment just above,
     * requests by other threads to exit the execution loop are expected to
     * be issued using the exit_request global. We must make sure that our
     * evaluation of the global value is performed past the current_cpu
     * value transition point, which requires a memory barrier as well as
     * an instruction scheduling constraint on modern architectures.  */
    smp_mb();

    rcu_read_lock();

    if (unlikely(exit_request)) {
        cpu->exit_request = 1;
    }

    cc->cpu_exec_enter(cpu);

    /* Calculate difference between guest clock and host clock.
     * This delay includes the delay of the last cycle, so
     * what we have to do is sleep until it is 0. As for the
     * advance/delay we gain here, we try to fix it next time.
     */
    init_delay_params(&sc, cpu);

    /* prepare setjmp context for exception handling */
    for(;;) {
        if (sigsetjmp(cpu->jmp_env, 0) == 0) {
            /* if an exception is pending, we execute it here */
            if (cpu->exception_index >= 0) {
                if (cpu->exception_index >= EXCP_INTERRUPT) {
                    /* exit request from the cpu execution loop */
                    ret = cpu->exception_index;
                    if (ret == EXCP_DEBUG) {
                        cpu_handle_debug_exception(env);
                    }
                    cpu->exception_index = -1;
                    break;
                } else {
#if defined(CONFIG_USER_ONLY)
                    /* if user mode only, we simulate a fake exception
                       which will be handled outside the cpu execution
                       loop */
#if defined(TARGET_I386)
                    cc->do_interrupt(cpu);
#endif
                    ret = cpu->exception_index;
                    cpu->exception_index = -1;
                    break;
#else
                    cc->do_interrupt(cpu);
                    cpu->exception_index = -1;
#endif
                }
            }

            next_tb = 0; /* force lookup of first TB */
            for(;;) {
                interrupt_request = cpu->interrupt_request;
                if (unlikely(interrupt_request)) {
                    if (unlikely(cpu->singlestep_enabled & SSTEP_NOIRQ)) {
                        /* Mask out external interrupts for this step. */
                        interrupt_request &= ~CPU_INTERRUPT_SSTEP_MASK;
                    }
                    if (interrupt_request & CPU_INTERRUPT_DEBUG) {
                        cpu->interrupt_request &= ~CPU_INTERRUPT_DEBUG;
                        cpu->exception_index = EXCP_DEBUG;
                        cpu_loop_exit(cpu);
                    }
                    if (interrupt_request & CPU_INTERRUPT_HALT) {
                        cpu->interrupt_request &= ~CPU_INTERRUPT_HALT;
                        cpu->halted = 1;
                        cpu->exception_index = EXCP_HLT;
                        cpu_loop_exit(cpu);
                    }
#if defined(TARGET_I386)
                    if (interrupt_request & CPU_INTERRUPT_INIT) {
                        cpu_svm_check_intercept_param(env, SVM_EXIT_INIT, 0);
                        do_cpu_init(x86_cpu);
                        cpu->exception_index = EXCP_HALTED;
                        cpu_loop_exit(cpu);
                    }
#else
                    if (interrupt_request & CPU_INTERRUPT_RESET) {
                        cpu_reset(cpu);
                    }
#endif
                    /* The target hook has 3 exit conditions:
                       False when the interrupt isn't processed,
                       True when it is, and we should restart on a new TB,
                       and via longjmp via cpu_loop_exit.  */
                    if (cc->cpu_exec_interrupt(cpu, interrupt_request)) {
                        next_tb = 0;
                    }
                    /* Don't use the cached interrupt_request value,
                       do_interrupt may have updated the EXITTB flag. */
                    if (cpu->interrupt_request & CPU_INTERRUPT_EXITTB) {
                        cpu->interrupt_request &= ~CPU_INTERRUPT_EXITTB;
                        /* ensure that no TB jump will be modified as
                           the program flow was changed */
                        next_tb = 0;
                    }
                }
                if (unlikely(cpu->exit_request)) {
                    cpu->exit_request = 0;
                    cpu->exception_index = EXCP_INTERRUPT;
                    cpu_loop_exit(cpu);
                }
                spin_lock(&tcg_ctx.tb_ctx.tb_lock);
                have_tb_lock = true;
                tb = tb_find_fast(env);
                /* Note: we do it here to avoid a gcc bug on Mac OS X when
                   doing it in tb_find_slow */
                if (tcg_ctx.tb_ctx.tb_invalidated_flag) {
                    /* as some TB could have been invalidated because
                       of memory exceptions while generating the code, we
                       must recompute the hash index here */
                    next_tb = 0;
                    tcg_ctx.tb_ctx.tb_invalidated_flag = 0;
                }

                if (qemu_loglevel_mask(CPU_LOG_EXEC)) {
                    qemu_log("Trace %p [" TARGET_FMT_lx "] %s\n",
                             tb->tc_ptr, tb->pc, lookup_symbol(tb->pc));
                }
/*
 * chaining complicates AFL's instrumentation so we disable it
 */
#ifdef NOPE_NOT_NEVER
                /* see if we can patch the calling TB. When the TB
                   spans two pages, we cannot safely do a direct
                   jump. */
                if (next_tb != 0 && tb->page_addr[1] == -1) {
                    tb_add_jump((TranslationBlock *)(next_tb & ~TB_EXIT_MASK),
                                next_tb & TB_EXIT_MASK, tb);
                }
#endif
                have_tb_lock = false;
                spin_unlock(&tcg_ctx.tb_ctx.tb_lock);

                /* cpu_interrupt might be called while translating the
                   TB, but before it is linked into a potentially
                   infinite loop and becomes env->current_tb. Avoid
                   starting execution if there is a pending interrupt. */
                cpu->current_tb = tb;
                barrier();
                if (likely(!cpu->exit_request)) {
                    trace_exec_tb(tb, tb->pc);
                    tc_ptr = tb->tc_ptr;

                    if (pm_stage == SR_R_EXPLORE && expl_started &&
                        (is_sr_func_ret_addr(tb->pc) || tb->pc > 0xfffffff0U)) {
                        stage_termination(SR_R_EXPLORE);
                        exit(0x21);
                    }

                    // Bo: record current bbl for unassigned_mem_read/write
                    cur_bbl_s = tb->pc;
                    cur_bbl_e = tb->pc+tb->size;

					// Bo: check whether address range is valid
                    extern CortexMState *cs_g;
                    if (!(cs_g->flash_base <= tb->pc && tb->pc < (cs_g->flash_base+(cs_g->flash_size_kb<<10))
        || cs_g->sram_base <= tb->pc && tb->pc < (cs_g->sram_base+(cs_g->sram_size_kb<<10))
        || cs_g->sram_size_kb2 && cs_g->sram_base2 <= tb->pc && tb->pc < (cs_g->sram_base2+(cs_g->sram_size_kb2<<10))
        || cs_g->sram_size_kb3 && cs_g->sram_base3 <= tb->pc && tb->pc < (cs_g->sram_base3+(cs_g->sram_size_kb3<<10))
                        //|| 0 <= tb->pc && tb->pc < (cs_g->flash_size_kb<<10)
                        //|| 0x0U <= tb->pc && tb->pc < 0x1000U
                        || 0xFFFFFFF0U <= tb->pc && tb->pc <= 0xFFFFFFFFU)) {
                        printf("[%x, %x] illegal exec at 0x%x\n", cur_bbl_s, cur_bbl_e, tb->pc);
#ifdef __OPEN_MULTI_STATUS__
				      	RECORD_ILLEGAL_OPERATION("exec", tb->pc);
#endif
                        exit(-1);
                    }

                    /* execute the generated code */
                    next_tb = cpu_tb_exec(tb->pc, cpu, tc_ptr, tb->size);
                    switch (next_tb & TB_EXIT_MASK) {
                    case TB_EXIT_REQUESTED:
                        /* Something asked us to stop executing
                         * chained TBs; just continue round the main
                         * loop. Whatever requested the exit will also
                         * have set something else (eg exit_request or
                         * interrupt_request) which we will handle
                         * next time around the loop.
                         */
                        next_tb = 0;
                        break;
                    case TB_EXIT_ICOUNT_EXPIRED:
                    {
                        /* Instruction counter expired.  */
                        int insns_left = cpu->icount_decr.u32;
                        if (cpu->icount_extra && insns_left >= 0) {
                            /* Refill decrementer and continue execution.  */
                            cpu->icount_extra += insns_left;
                            insns_left = MIN(0xffff, cpu->icount_extra);
                            cpu->icount_extra -= insns_left;
                            cpu->icount_decr.u16.low = insns_left;
                        } else {
                            if (insns_left > 0) {
                                /* Execute remaining instructions.  */
                                tb = (TranslationBlock *)(next_tb & ~TB_EXIT_MASK);
                                cpu_exec_nocache(env, insns_left, tb);
                                align_clocks(&sc, cpu);
                            }
                            cpu->exception_index = EXCP_INTERRUPT;
                            next_tb = 0;
                            cpu_loop_exit(cpu);
                        }
                        break;
                    }
                    default:
                        break;
                    }
                }
                cpu->current_tb = NULL;
                /* Try to align the host and virtual clocks
                   if the guest is in advance */
                align_clocks(&sc, cpu);
                /* reset soft MMU for next block (it can currently
                   only be set by a memory fault) */
            } /* for(;;) */
        } else {
            /* Reload env after longjmp - the compiler may have smashed all
             * local variables as longjmp is marked 'noreturn'. */
            cpu = current_cpu;
            env = cpu->env_ptr;
            cc = CPU_GET_CLASS(cpu);
            cpu->can_do_io = 1;
#ifdef TARGET_I386
            x86_cpu = X86_CPU(cpu);
#endif
            if (have_tb_lock) {
                spin_unlock(&tcg_ctx.tb_ctx.tb_lock);
                have_tb_lock = false;
            }
        }
    } /* for(;;) */

    cc->cpu_exec_exit(cpu);
    rcu_read_unlock();

    /* fail safe : never use current_cpu outside cpu_exec() */
    current_cpu = NULL;
    return ret;
}
