cmd_drivers/platform/built-in.a := rm -f drivers/platform/built-in.a;  printf "drivers/platform/%s " x86/built-in.a surface/built-in.a | xargs ar cDPrST drivers/platform/built-in.a
