/* Copyright 2016 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
/* Sweetberry board configuration */

#include "common.h"
#include "dma.h"
#include "ec_version.h"
#include "gpio.h"
#include "gpio_list.h"
#include "hooks.h"
#include "i2c.h"
#include "registers.h"
#include "stm32-dma.h"
#include "task.h"
#include "util.h"

/* I2C ports */
const struct i2c_port_t i2c_ports[] = {
	{"i2c1", I2C_PORT_0, 800,
		GPIO_I2C1_SCL, GPIO_I2C1_SDA},
	{"i2c2", I2C_PORT_1, 800,
		GPIO_I2C2_SCL, GPIO_I2C2_SDA},
	{"i2c3", I2C_PORT_2, 800,
		GPIO_I2C3_SCL, GPIO_I2C3_SDA},
	{"fmpi2c4", FMPI2C_PORT_3, 800,
		GPIO_FMPI2C_SCL, GPIO_FMPI2C_SDA},
};
const unsigned int i2c_ports_used = ARRAY_SIZE(i2c_ports);

#define GPIO_SET_HS(bank, number)	\
	(STM32_GPIO_OSPEEDR(GPIO_##bank) |= (0x3 << ((number) * 2)))

void board_config_post_gpio_init(void)
{
	/* We use MCO2 clock passthrough to provide a clock to USB HS */
	gpio_config_module(MODULE_MCO, 1);
	/* GPIO PC9 to high speed */
	GPIO_SET_HS(C,  9);

	/* Set USB GPIO to high speed */
	GPIO_SET_HS(A, 11);
	GPIO_SET_HS(A, 12);

	GPIO_SET_HS(C,  3);
	GPIO_SET_HS(C,  2);
	GPIO_SET_HS(C,  0);
	GPIO_SET_HS(A,  5);

	GPIO_SET_HS(B,  5);
	GPIO_SET_HS(B, 13);
	GPIO_SET_HS(B, 12);
	GPIO_SET_HS(B,  2);
	GPIO_SET_HS(B, 10);
	GPIO_SET_HS(B,  1);
	GPIO_SET_HS(B,  0);
	GPIO_SET_HS(A,  3);

	/* Set I2C GPIO to HS */
	GPIO_SET_HS(B,  6);
	GPIO_SET_HS(B,  7);
	GPIO_SET_HS(F,  1);
	GPIO_SET_HS(F,  0);
	GPIO_SET_HS(A,  8);
	GPIO_SET_HS(B,  4);
	GPIO_SET_HS(C,  6);
	GPIO_SET_HS(C,  7);
}

static void board_init(void)
{
	uint8_t tmp;

	/* i2c 0 has a tendancy to get wedged. TODO(nsanders): why? */
	i2c_xfer(0, 0, NULL, 0, &tmp, 1, I2C_XFER_SINGLE);
}
DECLARE_HOOK(HOOK_INIT, board_init, HOOK_PRIO_DEFAULT);
