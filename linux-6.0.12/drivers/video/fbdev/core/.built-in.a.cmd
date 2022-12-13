cmd_drivers/video/fbdev/core/built-in.a := rm -f drivers/video/fbdev/core/built-in.a;  printf "drivers/video/fbdev/core/%s " fb_cmdline.o | xargs ar cDPrST drivers/video/fbdev/core/built-in.a
