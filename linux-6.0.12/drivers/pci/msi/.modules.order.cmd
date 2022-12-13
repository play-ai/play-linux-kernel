cmd_drivers/pci/msi/modules.order := {  :; } | awk '!x[$$0]++' - > drivers/pci/msi/modules.order
