cmd_drivers/media/platform/rockchip/modules.order := {   cat drivers/media/platform/rockchip/rga/modules.order;   cat drivers/media/platform/rockchip/rkisp1/modules.order; :; } | awk '!x[$$0]++' - > drivers/media/platform/rockchip/modules.order
