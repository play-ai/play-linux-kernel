cmd_drivers/net/ethernet/cavium/modules.order := {   cat drivers/net/ethernet/cavium/common/modules.order;   cat drivers/net/ethernet/cavium/thunder/modules.order;   cat drivers/net/ethernet/cavium/liquidio/modules.order;   cat drivers/net/ethernet/cavium/octeon/modules.order; :; } | awk '!x[$$0]++' - > drivers/net/ethernet/cavium/modules.order
