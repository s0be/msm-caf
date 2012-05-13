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

/* Todo, I believe this is not supposed to be __initdata */
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

/* Liberty buttons in matrix:
 *
 *  Vol-up
 *  Vol-down
 *  Trackball Press
 *
 * I'm really just guessing for the values on the outputs.  I suspect they're wired
 * such that the 3 outputs are each connected to the 3 inputs, and when an output is
 * touched to an input, that registers a keypress.  It would make sense to drive them
 * high in this case.  They may not have a pull-up resistor on them, so going to 
 * GPIOMUX_PULL_NONE may be correct.
 * */

static struct gpiomux_setting liberty_keypad_matrix_key_out0 = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_4MA,
        .pull = GPIOMUX_PULL_UP,
        .dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting liberty_keypad_matrix_key_out1 = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_4MA,
        .pull = GPIOMUX_PULL_UP,
        .dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting liberty_keypad_matrix_key_out2 = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_4MA,
        .pull = GPIOMUX_PULL_UP,
        .dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting liberty_keypad_matrix_key_in0 = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_4MA,
        .pull = GPIOMUX_PULL_UP,
        .dir = GPIOMUX_IN,
};      
                
static struct gpiomux_setting liberty_keypad_matrix_key_in1 = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_4MA,
        .pull = GPIOMUX_PULL_UP,
        .dir = GPIOMUX_IN,
};

static struct gpiomux_setting liberty_keypad_matrix_key_in2 = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_4MA,
        .pull = GPIOMUX_PULL_UP,
        .dir = GPIOMUX_IN,
};

static struct msm_gpiomux_config liberty_keypad_matrix_configs[] __initdata = {
        {
                .gpio = LIBERTY_GPIO_KP_MKOUT0,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_keypad_matrix_key_out0,
                },
        },
	{
                .gpio = LIBERTY_GPIO_KP_MKOUT1,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_keypad_matrix_key_out1,
                },
        },
	{
                .gpio = LIBERTY_GPIO_KP_MKOUT2,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_keypad_matrix_key_out2,
                },
        },
	{
                .gpio = LIBERTY_GPIO_KP_MKIN0,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_keypad_matrix_key_in0,
                },
        },
	{
                .gpio = LIBERTY_GPIO_KP_MKIN1,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_keypad_matrix_key_in1,
                },
        },
	{
                .gpio = LIBERTY_GPIO_KP_MKIN2,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_keypad_matrix_key_in2,
                },
        },
};

/* Liberty Hardwired Buttons */
static struct gpiomux_setting liberty_keypad_hardwired_power = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_4MA,
        .pull = GPIOMUX_PULL_UP,
        .dir = GPIOMUX_IN,
};

static struct gpiomux_setting liberty_keypad_hardwired_reset = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_2MA,
        .pull = GPIOMUX_PULL_NONE,
        .dir = GPIOMUX_IN,
};

static struct msm_gpiomux_config liberty_keypad_hardwired_configs[] __initdata = {
	{
                .gpio = LIBERTY_POWER_KEY,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_keypad_hardwired_power,
                },
        },
        {
                .gpio = LIBERTY_GPIO_RESET_BTN_N,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_keypad_hardwired_reset,
                },
        },
};

/* Liberty Panel */
static struct gpiomux_setting liberty_panel_lcd_id0 = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_2MA,
        .pull = GPIOMUX_PULL_NONE,
        .dir = GPIOMUX_IN,
};

static struct gpiomux_setting liberty_panel_lcd_id1 = {
        .func = GPIOMUX_FUNC_GPIO,
        .drv = GPIOMUX_DRV_2MA,
        .pull = GPIOMUX_PULL_NONE,
        .dir = GPIOMUX_IN,
};

static struct gpiomux_setting liberty_panel_lcd_vsync = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
	.dir = GPIOMUX_IN,
};

static struct msm_gpiomux_config liberty_panel_configs[] __initdata = {
	{
                .gpio = LIBERTY_GPIO_LCD_ID0,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_panel_lcd_id0,
                },
        },
        {
                .gpio = LIBERTY_GPIO_LCD_ID1,
                .settings = {
                        [GPIOMUX_SUSPENDED] = &liberty_panel_lcd_id1,
                },
        },
	{
		.gpio = LIBERTY_GPIO_LCD_VSYNC,
		.settings = {
			[GPIOMUX_SUSPENDED] = &liberty_panel_lcd_vsync,
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

	msm_gpiomux_install(liberty_keypad_matrix_configs,
			ARRAY_SIZE(liberty_keypad_matrix_configs));

	msm_gpiomux_install(liberty_keypad_hardwired_configs,
			ARRAY_SIZE(liberty_keypad_hardwired_configs));

	msm_gpiomux_install(liberty_panel_configs,
			ARRAY_SIZE(liberty_panel_configs));

	return 0;
}
