/*
 * Copyright (C) 2009 Google, Inc.
 * Copyright (C) 2009 HTC Corporation.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

/* Control bluetooth power for liberty platform */

#include <linux/delay.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/rfkill.h>
#include <mach/gpio.h>
#include <mach/gpiomux.h>
#include <asm/mach-types.h>
//#include "../gpio_chip.h"
#include "board-liberty.h"

static struct rfkill *bt_rfk;
static const char bt_name[] = "bcm4329";

static void liberty_config_bt_init(void)
{
	/* 
	 * Only _get gpios that need to go into the active state and remain there.
	 * Don't touch gpios that need to toggle during init. Most of the init table
	 * was just dummy entries anyways... gpiomux now handles puting gpio pins 
	 * into a default state during init.
	 * */

	/* BT_RTS */
	/* BT_CTS */
	/* BT_RX */
	/* BT_TX */
	/* BT_RESET_N */
	/* BT_SHUTDOWN_N */
	/* BT_CHIP_WAKE */

}

static int liberty_config_bt_on(void)
{
	int rc = 0;
	/* set bt on configuration*/
	rc = msm_gpiomux_get(LIBERTY_GPIO_BT_UART1_RTS);
	if(rc)
		goto err_bt_uart1_rts;
	mdelay(2);

	rc = msm_gpiomux_get(LIBERTY_GPIO_BT_UART1_CTS);
	if(rc)
		goto err_bt_uart1_cts;
	mdelay(2);

	rc = msm_gpiomux_get(LIBERTY_GPIO_BT_UART1_RX);
	if(rc)
		goto err_bt_uart1_rx;
	mdelay(2);

	rc = msm_gpiomux_get(LIBERTY_GPIO_BT_UART1_TX);
	if(rc)
		goto err_bt_uart1_tx;
	mdelay(2);

	rc = msm_gpiomux_get(LIBERTY_GPIO_BT_CHIP_WAKE);
	if(rc)
		goto err_bt_chip_wake;
	mdelay(2);

	rc = msm_gpiomux_get(LIBERTY_GPIO_BT_RESET_N);
	if(rc)
		goto err_bt_reset_n;
	mdelay(2);

	rc = msm_gpiomux_get(LIBERTY_GPIO_BT_SHUTDOWN_N);
	if(rc)
		goto err_bt_shutdown_n;
	mdelay(2);

	return 0;

err_bt_shutdown_n:
	msm_gpiomux_put(LIBERTY_GPIO_BT_RESET_N);
err_bt_reset_n:
	msm_gpiomux_put(LIBERTY_GPIO_BT_CHIP_WAKE);
err_bt_chip_wake:
	msm_gpiomux_put(LIBERTY_GPIO_BT_UART1_TX);
err_bt_uart1_tx:
	msm_gpiomux_put(LIBERTY_GPIO_BT_UART1_RX);
err_bt_uart1_rx:
	msm_gpiomux_put(LIBERTY_GPIO_BT_UART1_CTS);
err_bt_uart1_cts:
	msm_gpiomux_put(LIBERTY_GPIO_BT_UART1_RTS);
err_bt_uart1_rts:
	return rc;
}

static void liberty_config_bt_off(void)
{
	/* BT_SHUTDOWN_N */
	msm_gpiomux_put(LIBERTY_GPIO_BT_SHUTDOWN_N);
	mdelay(2);
	msm_gpiomux_put(LIBERTY_GPIO_BT_RESET_N);
	mdelay(2);
	msm_gpiomux_put(LIBERTY_GPIO_BT_UART1_RTS);
        mdelay(2);
        msm_gpiomux_put(LIBERTY_GPIO_BT_UART1_CTS);
        mdelay(2);
        msm_gpiomux_put(LIBERTY_GPIO_BT_UART1_RX);
        mdelay(2);	
	msm_gpiomux_put(LIBERTY_GPIO_BT_UART1_TX);
        mdelay(2);	
	msm_gpiomux_put(LIBERTY_GPIO_BT_CHIP_WAKE);
        mdelay(2);	
}

#if 1
static int bluetooth_set_power(void *data, bool blocked)
{
	if (!blocked)
		liberty_config_bt_on();
	else
		liberty_config_bt_off();

	return 0;
}
#else
static int bluetooth_set_power(void *data, enum rfkill_state state)
{
	switch (state) {
	case RFKILL_STATE_UNBLOCKED:
		liberty_config_bt_on();
		break;
	case RFKILL_STATE_SOFT_BLOCKED:
		liberty_config_bt_off();
		break;
	default:
		pr_err("%s: bad rfkill state %d\n", __func__, state);
	}

	return 0;
}
#endif

#if 1
static struct rfkill_ops liberty_rfkill_ops = {
	.set_block = bluetooth_set_power,
};

static int liberty_rfkill_probe(struct platform_device *pdev)
{
	int rc = 0;
	bool default_state = true; /* off */

	liberty_config_bt_init();	/* bt gpio initial config */

	bluetooth_set_power(NULL, default_state);

	bt_rfk = rfkill_alloc(bt_name, &pdev->dev, RFKILL_TYPE_BLUETOOTH,
						 &liberty_rfkill_ops, NULL);
	if (!bt_rfk) {
		rc = -ENOMEM;
		goto err_rfkill_reset;
	}

	rfkill_set_states(bt_rfk, default_state, false);

	/* userspace cannot take exclusive control */
	rc = rfkill_register(bt_rfk);
	if (rc)
		goto err_rfkill_reg;

	return 0;

err_rfkill_reg:
	rfkill_destroy(bt_rfk);
err_rfkill_reset:
	return rc;
}
#else
static int liberty_rfkill_probe(struct platform_device *pdev)
{
	int rc = 0;
	enum rfkill_state default_state = RFKILL_STATE_SOFT_BLOCKED;

	liberty_config_bt_init();	/* bt gpio initial config */

	rfkill_set_default(RFKILL_TYPE_BLUETOOTH, default_state);
	bluetooth_set_power(NULL, default_state);

	bt_rfk = rfkill_allocate(&pdev->dev, RFKILL_TYPE_BLUETOOTH);
	if (!bt_rfk)
		return -ENOMEM;

	bt_rfk->name = bt_name;
	bt_rfk->state = default_state;

	/* userspace cannot take exclusive control */
	bt_rfk->user_claim_unsupported = 1;
	bt_rfk->user_claim = 0;
	bt_rfk->data = NULL;
	bt_rfk->toggle_radio = bluetooth_set_power;

	rc = rfkill_register(bt_rfk);
	if (rc)
		goto err_rfkill_reg;

	return 0;

err_rfkill_reg:
	rfkill_free(bt_rfk);
	return rc;
}
#endif

static int liberty_rfkill_remove(struct platform_device *dev)
{
	rfkill_unregister(bt_rfk);
	//rfkill_free(bt_rfk);
	rfkill_destroy(bt_rfk);

	return 0;
}

static struct platform_driver liberty_rfkill_driver = {
	.probe = liberty_rfkill_probe,
	.remove = liberty_rfkill_remove,
	.driver = {
		.name = "liberty_rfkill",
		.owner = THIS_MODULE,
	},
};

static int __init liberty_rfkill_init(void)
{
	if (!machine_is_msm7x27_liberty())
		return 0;

	return platform_driver_register(&liberty_rfkill_driver);
}

static void __exit liberty_rfkill_exit(void)
{
	platform_driver_unregister(&liberty_rfkill_driver);
}

module_init(liberty_rfkill_init);
module_exit(liberty_rfkill_exit);
MODULE_DESCRIPTION("liberty rfkill");
MODULE_AUTHOR("Nick Pelly <npelly@google.com>");
MODULE_LICENSE("GPL");
