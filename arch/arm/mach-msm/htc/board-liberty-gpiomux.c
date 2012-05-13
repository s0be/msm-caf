#include <asm/mach-types.h>
#include <mach/gpio.h>
#include <mach/gpiomux.h>
#include <mach/socinfo.h>
#include "../devices.h"
#include "board-liberty.h"

/* Bluetooth */

/* LIBERTY_GPIO_BT_UART1_RTS */
static struct gpiomux_setting liberty_bt_uart1_rts_act = {
	.func = GPIOMUX_FUNC_2,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting liberty_bt_uart1_rts_sus = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_IN,
};

/* LIBERTY_GPIO_BT_UART1_CTS */
static struct gpiomux_setting liberty_bt_uart1_cts_act = {
	.func = GPIOMUX_FUNC_2,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_OUT_LOW,
};

static struct gpiomux_setting liberty_bt_uart1_cts_sus = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_IN,
};

/* LIBERTY_GPIO_BT_UART1_RX */
static struct gpiomux_setting liberty_bt_uart1_rx_act = {
	.func = GPIOMUX_FUNC_2,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_IN,
};

static struct gpiomux_setting liberty_bt_uart1_rx_sus = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_IN,
};

/* LIBERTY_GPIO_BT_UART1_TX */
static struct gpiomux_setting liberty_bt_uart1_tx_act = {
	.func = GPIOMUX_FUNC_3,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting liberty_bt_uart1_tx_sus = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};

/* LIBERTY_GPIO_BT_RESET_N */
static struct gpiomux_setting liberty_bt_reset_n_act = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_4MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting liberty_bt_reset_n_sus = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_4MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};

/* LIBERTY_GPIO_BT_SHUTDOWN_N */
static struct gpiomux_setting liberty_bt_shutdown_n_act = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_4MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting liberty_bt_shutdown_n_sus = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_4MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};

/* LIBERTY_GPIO_BT_HOST_WAKE */
static struct gpiomux_setting liberty_bt_host_wake = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_4MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_IN,
};

/* LIBERTY_GPIO_BT_CHIP_WAKE */
static struct gpiomux_setting liberty_bt_chip_wake_act = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_4MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting liberty_bt_chip_wake_sus = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_4MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_OUT_LOW,
};

static struct msm_gpiomux_config liberty_bt_configs[] __initdata = {
	{
		.gpio = LIBERTY_GPIO_BT_UART1_RTS,
		.settings = {
			[GPIOMUX_ACTIVE] = &liberty_bt_uart1_rts_act,
			[GPIOMUX_SUSPENDED] = &liberty_bt_uart1_rts_sus,
		},
	}, 
	{
		.gpio = LIBERTY_GPIO_BT_UART1_CTS,
		.settings = {
			[GPIOMUX_ACTIVE] = &liberty_bt_uart1_cts_act,
			[GPIOMUX_SUSPENDED] = &liberty_bt_uart1_cts_sus,
		},
	},
	{
		.gpio = LIBERTY_GPIO_BT_UART1_RX,
		.settings = {
			[GPIOMUX_ACTIVE] = &liberty_bt_uart1_rx_act,
			[GPIOMUX_SUSPENDED] = &liberty_bt_uart1_rx_sus,
		},
	},
	{
		.gpio = LIBERTY_GPIO_BT_UART1_TX,
		.settings = {
			[GPIOMUX_ACTIVE] = &liberty_bt_uart1_tx_act,
			[GPIOMUX_SUSPENDED] = &liberty_bt_uart1_tx_sus,
		},
	},
	{
		.gpio = LIBERTY_GPIO_BT_RESET_N,
		.settings = {
			[GPIOMUX_ACTIVE] = &liberty_bt_reset_n_act,
			[GPIOMUX_SUSPENDED] = &liberty_bt_reset_n_sus,
		},
	},
	{
		.gpio = LIBERTY_GPIO_BT_SHUTDOWN_N,
		.settings = {
			[GPIOMUX_ACTIVE] = &liberty_bt_shutdown_n_act,
			[GPIOMUX_SUSPENDED] = &liberty_bt_shutdown_n_sus,
		},
	},
	{
		.gpio = LIBERTY_GPIO_BT_HOST_WAKE,
		.settings = {
			[GPIOMUX_SUSPENDED] = &liberty_bt_host_wake,
		},
	},
	{
		.gpio = LIBERTY_GPIO_BT_CHIP_WAKE,
		.settings = {
			[GPIOMUX_ACTIVE] = &liberty_bt_chip_wake_act,
			[GPIOMUX_SUSPENDED] = &liberty_bt_chip_wake_sus,
		},
	},
};

int __init liberty_init_gpiomux(void)
{
        int rc = msm_gpiomux_init(NR_GPIO_IRQS);
        if (rc) {
                pr_err(KERN_ERR "msm_gpiomux_init failed %d\n", rc);
                return rc;
        }

        msm_gpiomux_install(liberty_bt_configs,
                        ARRAY_SIZE(liberty_bt_configs));

	return 0;
}
