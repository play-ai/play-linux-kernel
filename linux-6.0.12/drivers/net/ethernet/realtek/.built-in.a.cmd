cmd_drivers/net/ethernet/realtek/built-in.a := rm -f drivers/net/ethernet/realtek/built-in.a;  printf "drivers/net/ethernet/realtek/%s " 8139too.o r8169_main.o r8169_firmware.o r8169_phy_config.o | xargs ar cDPrST drivers/net/ethernet/realtek/built-in.a