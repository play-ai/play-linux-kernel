cmd_drivers/tty/serial/built-in.a := rm -f drivers/tty/serial/built-in.a;  printf "drivers/tty/serial/%s " serial_core.o earlycon.o 8250/built-in.a | xargs ar cDPrST drivers/tty/serial/built-in.a
