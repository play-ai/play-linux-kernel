cmd_drivers/pci/pcie/built-in.a := rm -f drivers/pci/pcie/built-in.a;  printf "drivers/pci/pcie/%s " portdrv_core.o portdrv_pci.o rcec.o aspm.o pme.o | xargs ar cDPrST drivers/pci/pcie/built-in.a
