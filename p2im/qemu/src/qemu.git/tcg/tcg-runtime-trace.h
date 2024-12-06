DEF_HELPER_FLAGS_2(trace_insn, TCG_CALL_NO_RWG, void, env, i64)

/* Guest memory */
DEF_HELPER_FLAGS_6(trace_load_guest_i32, TCG_CALL_NO_RWG, void, env, i64, i32, dh_alias_tl, i64, dh_alias_tl)
DEF_HELPER_FLAGS_6(trace_load_guest_i64, TCG_CALL_NO_RWG, void, env, i64, i64, dh_alias_tl, i64, dh_alias_tl)
DEF_HELPER_FLAGS_6(trace_store_guest_i32, TCG_CALL_NO_RWG, void, env, i64, i32, dh_alias_tl, i64, dh_alias_tl)
DEF_HELPER_FLAGS_6(trace_store_guest_i64, TCG_CALL_NO_RWG, void, env, i64, i64, dh_alias_tl, i64, dh_alias_tl)

/* Host memory */
DEF_HELPER_FLAGS_6(trace_load_host_i32, TCG_CALL_NO_RWG_SE, void, env, i64, i32, ptr, i64, i64)
DEF_HELPER_FLAGS_6(trace_load_host_i64, TCG_CALL_NO_RWG_SE, void, env, i64, i64, ptr, i64, i64)
DEF_HELPER_FLAGS_6(trace_store_host_i32, TCG_CALL_NO_RWG, void, env, i64, i32, ptr, i64, i64)
DEF_HELPER_FLAGS_6(trace_store_host_i64, TCG_CALL_NO_RWG, void, env, i64, i64, ptr, i64, i64)
