cmd_drivers/crypto/built-in.a := rm -f drivers/crypto/built-in.a;  printf "drivers/crypto/%s " xilinx/built-in.a hisilicon/built-in.a keembay/built-in.a | xargs ar cDPrST drivers/crypto/built-in.a
