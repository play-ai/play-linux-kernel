cmd_arch/x86/events/built-in.a := rm -f arch/x86/events/built-in.a;  printf "arch/x86/events/%s " core.o probe.o rapl.o amd/built-in.a msr.o intel/built-in.a zhaoxin/built-in.a | xargs ar cDPrST arch/x86/events/built-in.a
