cmd_drivers/usb/host/built-in.a := rm -f drivers/usb/host/built-in.a;  printf "drivers/usb/host/%s " pci-quirks.o ehci-hcd.o ehci-pci.o ohci-hcd.o ohci-pci.o uhci-hcd.o xhci.o xhci-mem.o xhci-ext-caps.o xhci-ring.o xhci-hub.o xhci-dbg.o xhci-trace.o xhci-debugfs.o xhci-pci.o | xargs ar cDPrST drivers/usb/host/built-in.a