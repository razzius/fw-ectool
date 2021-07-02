/* Copyright 2018 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Atlas board configuration */

#ifndef __CROS_EC_BOARD_H
#define __CROS_EC_BOARD_H

/*
 * By default, enable all console messages excepted HC, ACPI and event:
 * The sensor stack is generating a lot of activity.
 */
#define CC_DEFAULT     (CC_ALL & ~(CC_MASK(CC_EVENTS) | CC_MASK(CC_LPC)))
#undef CONFIG_HOSTCMD_DEBUG_MODE
#define CONFIG_HOSTCMD_DEBUG_MODE HCDEBUG_OFF

/* EC */
#define CONFIG_ADC
#define CONFIG_BOARD_FORCE_RESET_PIN
#define CONFIG_DPTF
#define CONFIG_FPU
#define CONFIG_I2C
#define CONFIG_I2C_CONTROLLER
#define CONFIG_LID_SWITCH
#define CONFIG_LOW_POWER_IDLE
#define CONFIG_LTO
#define CONFIG_CHIP_PANIC_BACKUP
#define CONFIG_SOFTWARE_PANIC
#define CONFIG_PWM
#define CONFIG_PWM_KBLIGHT
#define CONFIG_SHA256_UNROLLED

/* Internal SPI flash on NPCX7 */
#define CONFIG_FLASH_SIZE_BYTES (512 * 1024) /* It's really 1MB. */
#define CONFIG_SPI_FLASH_REGS
#define CONFIG_SPI_FLASH_W25Q80 /* Internal SPI flash type. */

#define CONFIG_VBOOT_HASH
#define CONFIG_VSTORE
#define CONFIG_VSTORE_SLOT_COUNT 1
#define CONFIG_WATCHDOG_HELP

/* EC console commands */
#define CONFIG_CMD_ACCELS
#define CONFIG_CMD_ACCEL_INFO
#define CONFIG_CMD_BATT_MFG_ACCESS
#define CONFIG_CMD_CHARGER_ADC_AMON_BMON
#define CONFIG_HOSTCMD_PD_CONTROL

/* SOC */
#define CONFIG_CHIPSET_SKYLAKE
#define CONFIG_CHIPSET_HAS_PLATFORM_PMIC_RESET
#define CONFIG_CHIPSET_RESET_HOOK
#define CONFIG_CPU_PROCHOT_ACTIVE_LOW
#define CONFIG_HOSTCMD_ESPI
#define CONFIG_HOSTCMD_ESPI_VW_SLP_S3
#define CONFIG_HOSTCMD_ESPI_VW_SLP_S4
#define CONFIG_KEYBOARD_BOARD_CONFIG
#define CONFIG_KEYBOARD_COL2_INVERTED
#define CONFIG_KEYBOARD_PROTOCOL_8042
#define CONFIG_KEYBOARD_REFRESH_ROW3

/* Battery */
#define CONFIG_BATTERY_CUT_OFF
#define CONFIG_BATTERY_DEVICE_CHEMISTRY "LION"
#define CONFIG_BATTERY_LEVEL_NEAR_FULL 95
#define CONFIG_BATTERY_HW_PRESENT_CUSTOM
#define CONFIG_BATTERY_PRESENT_CUSTOM
#define CONFIG_BATTERY_SMART
/* battery briefly requests V=0, A=0 when woken up */
#define CONFIG_BATTERY_REQUESTS_NIL_WHEN_DEAD

/* Charger */
#define CONFIG_CHARGE_MANAGER
#define CONFIG_CHARGE_MANAGER_EXTERNAL_POWER_LIMIT
#define CONFIG_CHARGER
#define CONFIG_CHARGER_ISL9238
#define CONFIG_CHARGER_DISCHARGE_ON_AC
#define CONFIG_CHARGER_INPUT_CURRENT 512
#define CONFIG_CHARGER_PROFILE_OVERRIDE
#define CONFIG_CHARGER_PSYS
#define CONFIG_CHARGER_PSYS_READ
#define CONFIG_CHARGER_SENSE_RESISTOR 10
#define CONFIG_CHARGER_SENSE_RESISTOR_AC 20
#define CONFIG_EXTPOWER_GPIO
#define CONFIG_POWER_BUTTON
#define CONFIG_POWER_BUTTON_X86
#define CONFIG_POWER_COMMON
#define CONFIG_POWER_SIGNAL_INTERRUPT_STORM_DETECT_THRESHOLD 30
#define CONFIG_POWER_S0IX
#define CONFIG_POWER_TRACK_HOST_SLEEP_STATE
#define CONFIG_PWR_STATE_DISCHARGE_FULL

/* LEDs */
#define CONFIG_LED_COMMON
#define CONFIG_LED_PWM_ACTIVE_CHARGE_PORT_ONLY
#define CONFIG_LED_PWM_COUNT 2
#undef CONFIG_LED_PWM_NEAR_FULL_COLOR
#define CONFIG_LED_PWM_NEAR_FULL_COLOR EC_LED_COLOR_WHITE

/* Temperature Sensor */
#define CONFIG_TEMP_SENSOR
#define CONFIG_TEMP_SENSOR_BD99992GW
#define CONFIG_THERMISTOR_NCP15WB

/* Sensor */
#define CONFIG_MKBP_EVENT
#define CONFIG_MKBP_USE_HOST_EVENT
#define CONFIG_ALS
#define CONFIG_ALS_OPT3001
#define ALS_COUNT 1
#define OPT3001_I2C_ADDR_FLAGS OPT3001_I2C_ADDR1_FLAGS
/* Enable sensor fifo, must also define the _SIZE and _THRES */
#define CONFIG_ACCEL_FIFO
/* FIFO size is a power of 2. */
#define CONFIG_ACCEL_FIFO_SIZE 1024
/* Depends on how fast the AP boots and typical ODRs. */
#define CONFIG_ACCEL_FIFO_THRES (CONFIG_ACCEL_FIFO_SIZE / 3)
#define CONFIG_ACCEL_INTERRUPTS

/* USB */
#define CONFIG_USB_PD_ALT_MODE
#define CONFIG_USB_PD_ALT_MODE_DFP
#define CONFIG_USB_PD_COMM_LOCKED
#define CONFIG_USB_PD_DISCHARGE
#define CONFIG_USB_PD_DISCHARGE_TCPC
#define CONFIG_USB_PD_DUAL_ROLE
#define CONFIG_USB_PD_DUAL_ROLE_AUTO_TOGGLE
#define CONFIG_USB_PD_LOGGING
#define CONFIG_USB_PD_MAX_SINGLE_SOURCE_CURRENT TYPEC_RP_3A0
#define CONFIG_USB_PD_PORT_MAX_COUNT 2
#define CONFIG_USB_PD_VBUS_DETECT_TCPC
#define CONFIG_USB_PD_TCPC_LOW_POWER
#define CONFIG_USB_PD_TCPM_MUX
#define CONFIG_USB_PD_TCPM_PS8751
#define CONFIG_USB_PD_TCPM_TCPCI
#define CONFIG_USB_PD_TRY_SRC
#undef CONFIG_USB_PD_TRY_SRC_MIN_BATT_SOC
#define CONFIG_USB_PD_TRY_SRC_MIN_BATT_SOC 2
#define CONFIG_USB_PD_VBUS_MEASURE_NOT_PRESENT
#define CONFIG_USB_POWER_DELIVERY
#define CONFIG_USB_PD_TCPMV1
#define CONFIG_USBC_SS_MUX
#define CONFIG_USBC_SS_MUX_DFP_ONLY /* FIXME: b/77151299 */
#define CONFIG_USBC_VCONN
#define CONFIG_USBC_VCONN_SWAP

/* Optional feature to configure npcx chip */
#define NPCX_UART_MODULE2	1 /* 1:GPIO64/65 as UART */
#define NPCX_JTAG_MODULE2	0 /* 0:GPIO21/17/16/20 as JTAG */
#define NPCX_TACH_SEL2		0 /* 0:GPIO40/73 1:GPIO93/A6 as TACH */
#define NPCX7_PWM1_SEL		1 /* GPIO C2 is used as PWM1. */
#define CONFIG_HIBERNATE_PSL	/* Enable PSL pins for wakeup */

/* I2C ports */
#define I2C_PORT_POWER		NPCX_I2C_PORT0_0	/* pmic/charger */
#define I2C_PORT_TCPC0		NPCX_I2C_PORT1_0
#define I2C_PORT_TCPC1		NPCX_I2C_PORT2_0
#define I2C_PORT_SENSOR		NPCX_I2C_PORT3_0	/* als */
#define I2C_PORT_BATTERY	NPCX_I2C_PORT4_1
#define I2C_PORT_GYRO		NPCX_I2C_PORT5_0	/* accel/gyro */

#define I2C_PORT_ACCEL		I2C_PORT_GYRO
#define I2C_PORT_CHARGER	I2C_PORT_POWER
#define I2C_PORT_PMIC		I2C_PORT_POWER
#define I2C_PORT_THERMAL	I2C_PORT_POWER

/* I2C addresses */
#define I2C_ADDR_TCPC_FLAGS	0x0B
#define I2C_ADDR_MP2949_FLAGS	0x20
#define I2C_ADDR_BD99992_FLAGS	0x30

#ifndef __ASSEMBLER__

#include "gpio_signal.h"
#include "registers.h"

enum temp_sensor_id {
	TEMP_SENSOR_BATTERY,	/* BD99956GW TSENSE */
	TEMP_SENSOR_SYSTHERM0,	/* BD99992GW SYSTHERM0 */
	TEMP_SENSOR_SYSTHERM1,	/* BD99992GW SYSTHERM1 */
	TEMP_SENSOR_SYSTHERM2,	/* BD99992GW SYSTHERM2 */
	TEMP_SENSOR_SYSTHERM3,	/* BD99992GW SYSTHERM3 */
	TEMP_SENSOR_COUNT
};

enum pwm_channel {
	PWM_CH_KBLIGHT,
	PWM_CH_DB0_LED_BLUE,
	PWM_CH_DB0_LED_RED,
	PWM_CH_DB0_LED_GREEN,
	PWM_CH_DB1_LED_BLUE,
	PWM_CH_DB1_LED_RED,
	PWM_CH_DB1_LED_GREEN,
	PWM_CH_COUNT
};

enum sensor_id {
	LID_ALS,
	SENSOR_COUNT,
};

/* LID_ALS needs to be polled */
#define CONFIG_ACCEL_FORCE_MODE_MASK	BIT(LID_ALS)

enum adc_channel {
	ADC_AMON_BMON,
	ADC_PSYS,
	ADC_CH_COUNT
};

/*
 * delay to turn on the power supply max is ~16ms.
 * delay to turn off the power supply max is about ~180ms.
 */
#define PD_POWER_SUPPLY_TURN_ON_DELAY	30000  /* us */
#define PD_POWER_SUPPLY_TURN_OFF_DELAY	250000 /* us */

/* delay to turn on/off vconn */

/* Define typical operating power and max power */
#define PD_OPERATING_POWER_MW		15000
#define PD_MAX_POWER_MW			60000
#define PD_MAX_CURRENT_MA		3000
#define PD_MAX_VOLTAGE_MV		20000

/* Board specific handlers */
int board_get_version(void);
void board_reset_pd_mcu(void);

#endif /* !__ASSEMBLER__ */

/*
 * these are mappings from signal names used in the atlas schematics
 * vs. names hard-coded in various parts of the EC codebase.
 */

#define GPIO_AC_PRESENT		GPIO_ROP_EC_ACOK
#define GPIO_BATTERY_PRESENT_L	GPIO_EC_BATT_PRES_L
#define GPIO_BOARD_VERSION1	GPIO_EC_BRD_ID1
#define GPIO_BOARD_VERSION2	GPIO_EC_BRD_ID2
#define GPIO_BOARD_VERSION3	GPIO_EC_BRD_ID3
#define GPIO_CPU_PROCHOT	GPIO_EC_PROCHOT_ODL
#define GPIO_ENTERING_RW	GPIO_EC_ENTERING_RW
#define GPIO_KBD_KSO2		GPIO_EC_KB_ROW02_INV
#define GPIO_PCH_ACOK		GPIO_EC_PCH_ACPRESENT
#define GPIO_PCH_PWRBTN_L	GPIO_EC_PCH_PWR_BTN_L
#define GPIO_PCH_RSMRST_L	GPIO_RSMRST_L
#define GPIO_PCH_SLP_SUS_L	GPIO_SLP_SUS_L_PCH
#define GPIO_PCH_WAKE_L		GPIO_EC_PCH_WAKE_L
#define GPIO_PMIC_DPWROK	GPIO_ROP_DSW_PWROK_EC
#define GPIO_PMIC_SLP_SUS_L	GPIO_SLP_SUS_L_PMIC
#define GPIO_POWER_BUTTON_L	GPIO_MECH_PWR_BTN_ODL
#define GPIO_RSMRST_L_PGOOD	GPIO_ROP_EC_RSMRST_L
#define GPIO_PCH_SLP_S0_L	GPIO_SLP_S0_L
#define GPIO_USB_C0_5V_EN	GPIO_EN_USB_C0_5V_OUT
#define GPIO_USB_C0_PD_RST_L	GPIO_USB_PD_RST_L
#define GPIO_USB_C1_5V_EN	GPIO_EN_USB_C1_5V_OUT
#define GPIO_USB_C1_PD_RST_L	GPIO_USB_PD_RST_L
#define GPIO_WP_L		GPIO_EC_WP_L

/* ps8751 requires 1ms reset down assertion */
#define PS8XXX_RST_L_RST_H_DELAY_MS	1

#define ATLAS_REV_FIXED_EC_WP	4

#endif /* __CROS_EC_BOARD_H */
