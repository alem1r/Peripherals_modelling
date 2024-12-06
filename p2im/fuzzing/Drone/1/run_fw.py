#!/usr/bin/env python3
import sys,subprocess
if len(sys.argv) < 3 or len(sys.argv) > 4:
    print("Usage: %s last_round_of_model_instantiation test_case [--debug]" % sys.argv[0])
    print("	--debug argument is optional. It halts QEMU and wait for a debugger to be attached")
    sys.exit(-1)

cmd = ['/home/alessandro/Peripherals_modelling/p2im/qemu/precompiled_bin/qemu-system-gnuarmeclipse', '-nographic', '-board', 'NUCLEO-F103RB', '-mcu', 'STM32F103RB', '-image', '/home/alessandro/Peripherals_modelling/p2im/fuzzing/Drone/1/Drone.elf', '-pm-stage', '3', '-aflFile', sys.argv[2], '-model-input', '/home/alessandro/Peripherals_modelling/p2im/fuzzing/Drone/1/%s/peripheral_model.json' % sys.argv[1]]

if len(sys.argv) == 4 and sys.argv[3] == '--debug':
    # halt qemu and wait for a debugger to be attached
    cmd+=['-gdb', 'tcp::9000', '-S']
print(cmd)

subprocess.call(cmd)
