cmd_drivers/clk/modules.order := {   cat drivers/clk/actions/modules.order;   cat drivers/clk/analogbits/modules.order;   cat drivers/clk/bcm/modules.order;   cat drivers/clk/imgtec/modules.order;   cat drivers/clk/imx/modules.order;   cat drivers/clk/ingenic/modules.order;   cat drivers/clk/mediatek/modules.order;   cat drivers/clk/microchip/modules.order;   cat drivers/clk/mstar/modules.order;   cat drivers/clk/mvebu/modules.order;   cat drivers/clk/ralink/modules.order;   cat drivers/clk/renesas/modules.order;   cat drivers/clk/socfpga/modules.order;   cat drivers/clk/sprd/modules.order;   cat drivers/clk/sunxi-ng/modules.order;   cat drivers/clk/ti/modules.order;   cat drivers/clk/versatile/modules.order;   cat drivers/clk/xilinx/modules.order; :; } | awk '!x[$$0]++' - > drivers/clk/modules.order