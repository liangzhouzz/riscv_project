/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2014, Marcel Ziswiler
 */

#ifndef _PINMUX_CONFIG_APALIS_T30_H_
#define _PINMUX_CONFIG_APALIS_T30_H_

#define DEFAULT_PINMUX(_pingrp, _mux, _pull, _tri, _io)		\
	{							\
		.pingrp		= PMUX_PINGRP_##_pingrp,	\
		.func		= PMUX_FUNC_##_mux,		\
		.pull		= PMUX_PULL_##_pull,		\
/* TRISTATE here means output driver is tri-stated */ \
		.tristate	= PMUX_TRI_##_tri,		\
/* INPUT here means input driver is enabled vs. OUTPUT where it is disabled */ \
		.io		= PMUX_PIN_##_io,		\
		.lock		= PMUX_PIN_LOCK_DEFAULT,	\
		.od		= PMUX_PIN_OD_DEFAULT,		\
		.ioreset	= PMUX_PIN_IO_RESET_DEFAULT,	\
	}

#define I2C_PINMUX(_pingrp, _mux, _pull, _tri, _io, _lock, _od)	\
	{							\
		.pingrp		= PMUX_PINGRP_##_pingrp,	\
		.func		= PMUX_FUNC_##_mux,		\
		.pull		= PMUX_PULL_##_pull,		\
		.tristate	= PMUX_TRI_##_tri,		\
		.io		= PMUX_PIN_##_io,		\
		.lock		= PMUX_PIN_LOCK_##_lock,	\
		.od		= PMUX_PIN_OD_##_od,		\
		.ioreset	= PMUX_PIN_IO_RESET_DEFAULT,	\
	}

#define LV_PINMUX(_pingrp, _mux, _pull, _tri, _io, _lock, _ioreset) \
	{							\
		.pingrp		= PMUX_PINGRP_##_pingrp,	\
		.func		= PMUX_FUNC_##_mux,		\
		.pull		= PMUX_PULL_##_pull,		\
		.tristate	= PMUX_TRI_##_tri,		\
		.io		= PMUX_PIN_##_io,		\
		.lock		= PMUX_PIN_LOCK_##_lock,	\
		.od		= PMUX_PIN_OD_DEFAULT,		\
		.ioreset	= PMUX_PIN_IO_RESET_##_ioreset	\
	}

#define DEFAULT_PADCFG(_drvgrp, _slwf, _slwr, _drvup, _drvdn, _lpmd, _schmt, _hsm) \
	{							\
		.drvgrp		= PMUX_DRVGRP_##_drvgrp,	\
		.slwf		= _slwf,			\
		.slwr		= _slwr,			\
		.drvup		= _drvup,			\
		.drvdn		= _drvdn,			\
		.lpmd		= PMUX_LPMD_##_lpmd,		\
		.schmt		= PMUX_SCHMT_##_schmt,		\
		.hsm		= PMUX_HSM_##_hsm,		\
	}

static struct pmux_pingrp_config tegra3_pinmux_common[] = {
	/* SDMMC1 pinmux */
	DEFAULT_PINMUX(SDMMC1_CLK_PZ0, SDMMC1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC1_CMD_PZ1, SDMMC1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC1_DAT3_PY4, SDMMC1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC1_DAT2_PY5, SDMMC1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC1_DAT1_PY6, SDMMC1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC1_DAT0_PY7, SDMMC1, NORMAL, NORMAL, INPUT),

	/* SDMMC3 pinmux */
	DEFAULT_PINMUX(SDMMC3_CLK_PA6, SDMMC3, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC3_CMD_PA7, SDMMC3, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT0_PB7, SDMMC3, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT1_PB6, SDMMC3, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT2_PB5, SDMMC3, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT3_PB4, SDMMC3, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT4_PD1, SDMMC3, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT5_PD0, SDMMC3, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT6_PD3, SDMMC3, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SDMMC3_DAT7_PD4, SDMMC3, NORMAL, NORMAL, INPUT),

	/* SDMMC4 pinmux (eMMC) */
	LV_PINMUX(SDMMC4_CLK_PCC4, SDMMC4, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_CMD_PT7, SDMMC4, UP, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_DAT0_PAA0, SDMMC4, UP, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_DAT1_PAA1, SDMMC4, UP, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_DAT2_PAA2, SDMMC4, UP, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_DAT3_PAA3, SDMMC4, UP, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_DAT4_PAA4, SDMMC4, UP, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_DAT5_PAA5, SDMMC4, UP, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_DAT6_PAA6, SDMMC4, UP, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_DAT7_PAA7, SDMMC4, UP, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(SDMMC4_RST_N_PCC3, RSVD1, DOWN, NORMAL, INPUT, DISABLE, DISABLE),

	/* I2C1 pinmux */
	I2C_PINMUX(GEN1_I2C_SCL_PC4, I2C1, NORMAL, NORMAL, INPUT, DISABLE, ENABLE),
	I2C_PINMUX(GEN1_I2C_SDA_PC5, I2C1, NORMAL, NORMAL, INPUT, DISABLE, ENABLE),

	/* I2C2 pinmux */
	I2C_PINMUX(GEN2_I2C_SCL_PT5, RSVD3, NORMAL, NORMAL, INPUT, DEFAULT, DISABLE),
	I2C_PINMUX(GEN2_I2C_SDA_PT6, RSVD3, NORMAL, NORMAL, INPUT, DEFAULT, DISABLE),

	/* I2C3 pinmux */
	I2C_PINMUX(CAM_I2C_SCL_PBB1, I2C3, NORMAL, TRISTATE, INPUT, DISABLE, ENABLE),
	I2C_PINMUX(CAM_I2C_SDA_PBB2, I2C3, NORMAL, TRISTATE, INPUT, DISABLE, ENABLE),

	/* I2C4 pinmux */
	I2C_PINMUX(DDC_SCL_PV4, I2C4, NORMAL, NORMAL, INPUT, DISABLE, ENABLE),
	I2C_PINMUX(DDC_SDA_PV5, I2C4, NORMAL, NORMAL, INPUT, DISABLE, ENABLE),

	/* Power I2C pinmux */
	I2C_PINMUX(PWR_I2C_SCL_PZ6, I2CPWR, NORMAL, NORMAL, INPUT, DISABLE, ENABLE),
	I2C_PINMUX(PWR_I2C_SDA_PZ7, I2CPWR, NORMAL, NORMAL, INPUT, DISABLE, ENABLE),

	DEFAULT_PINMUX(ULPI_DATA0_PO1, UARTA, NORMAL, NORMAL, OUTPUT),
	/* UARTA RX, make sure we don't get input form a floating Pin */
	DEFAULT_PINMUX(ULPI_DATA1_PO2, UARTA, UP, NORMAL, INPUT),
	DEFAULT_PINMUX(ULPI_DATA2_PO3, UARTA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(ULPI_DATA3_PO4, RSVD1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(ULPI_DATA4_PO5, UARTA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(ULPI_DATA5_PO6, UARTA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(ULPI_DATA6_PO7, UARTA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(ULPI_DATA7_PO0, UARTA, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(ULPI_CLK_PY0, UARTD, NORMAL, NORMAL, OUTPUT),
	/* UARTD RX, make sure we don't get input form a floating Pin */
	DEFAULT_PINMUX(ULPI_DIR_PY1, UARTD, UP, NORMAL, INPUT),
	DEFAULT_PINMUX(ULPI_NXT_PY2, UARTD, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(ULPI_STP_PY3, UARTD, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(DAP3_FS_PP0, I2S2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(DAP3_DIN_PP1, I2S2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(DAP3_DOUT_PP2, I2S2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(DAP3_SCLK_PP3, I2S2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(PV2, OWR, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(PV3, RSVD1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(CLK2_OUT_PW5, EXTPERIPH2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(CLK2_REQ_PCC5, DAP, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_PWR1_PC1, DISPLAYA, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(LCD_PWR2_PC6, DISPLAYA, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(LCD_SDIN_PZ2, SPI5, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_SDOUT_PN5, SPI5, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_WR_N_PZ3, DISPLAYA, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(LCD_CS0_N_PN4, SPI5, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_DC0_PN6, DISPLAYA, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(LCD_SCK_PZ4, SPI5, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_PWR0_PB2, DISPLAYA, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(LCD_PCLK_PB3, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_DE_PJ1, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_HSYNC_PJ3, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_VSYNC_PJ4, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D0_PE0, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D1_PE1, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D2_PE2, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D3_PE3, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D4_PE4, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D5_PE5, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D6_PE6, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D7_PE7, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D8_PF0, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D9_PF1, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D10_PF2, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D11_PF3, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D12_PF4, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D13_PF5, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D14_PF6, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D15_PF7, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D16_PM0, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D17_PM1, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D18_PM2, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D19_PM3, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D20_PM4, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D21_PM5, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D22_PM6, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_D23_PM7, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(LCD_CS1_N_PW0, DISPLAYA, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(LCD_M1_PW1, DISPLAYA, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(LCD_DC1_PD2, DISPLAYA, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(CRT_HSYNC_PV6, CRT, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(CRT_VSYNC_PV7, CRT, NORMAL, NORMAL, OUTPUT),
	LV_PINMUX(VI_D0_PT4, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D1_PD5, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D2_PL0, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D3_PL1, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D4_PL2, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D5_PL3, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D6_PL4, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D7_PL5, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D8_PL6, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D9_PL7, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D10_PT2, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_D11_PT3, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_HSYNC_PD7, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_MCLK_PT1, VI, NORMAL, NORMAL, OUTPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_PCLK_PT0, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	LV_PINMUX(VI_VSYNC_PD6, VI, NORMAL, NORMAL, INPUT, DISABLE, DISABLE),
	/* UARTB RX, make sure we don't get input form a floating Pin */
	DEFAULT_PINMUX(UART2_RXD_PC3, UARTB, UP, NORMAL, INPUT),
	DEFAULT_PINMUX(UART2_TXD_PC2, UARTB, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(UART2_RTS_N_PJ6, UARTB, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(UART2_CTS_N_PJ5, UARTB, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(UART3_TXD_PW6, UARTC, NORMAL, NORMAL, OUTPUT),
	/* UARTC RX, make sure we don't get input form a floating Pin */
	DEFAULT_PINMUX(UART3_RXD_PW7, UARTC, UP, NORMAL, INPUT),
	DEFAULT_PINMUX(UART3_CTS_N_PA1, UARTC, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(UART3_RTS_N_PC0, PWM0, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PU0, RSVD1, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(PU1, RSVD1, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(PU2, RSVD1, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(PU3, PWM0, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PU4, PWM1, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PU5, PWM2, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PU6, PWM3, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(DAP4_FS_PP4, I2S3, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(DAP4_DIN_PP5, I2S3, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(DAP4_DOUT_PP6, I2S3, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(DAP4_SCLK_PP7, I2S3, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(CLK3_OUT_PEE0, EXTPERIPH3, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(CLK3_REQ_PEE1, DEV3, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_WP_N_PC7, GMI, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_CS2_N_PK3, RSVD1, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_AD8_PH0, PWM0, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_AD10_PH2, NAND, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_A16_PJ7, UARTD, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_A17_PB0, UARTD, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_A18_PB1, UARTD, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_A19_PK7, UARTD, DOWN, TRISTATE, OUTPUT), /* NC */

	DEFAULT_PINMUX(CAM_MCLK_PCC0, VI_ALT2, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PBB0, RSVD1, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PBB3, VGP3, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PBB4, VGP4, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PBB5, VGP5, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PBB6, VGP6, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PBB7, I2S4, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PCC1, RSVD1, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PCC2, I2S4, NORMAL, NORMAL, OUTPUT),

	DEFAULT_PINMUX(JTAG_RTCK_PU7, RTCK, NORMAL, NORMAL, OUTPUT),

	/* multiplexed VI_D2, VI_D3, VI_D4, VI_D5, VI_D6, VI_D7, VI_D8 and VI_D9
	 */
	DEFAULT_PINMUX(KB_ROW0_PR0, RSVD2, NORMAL, TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW1_PR1, RSVD2, NORMAL, TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW2_PR2, RSVD2, NORMAL, TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW3_PR3, RSVD2, NORMAL, TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW4_PR4, RSVD3, NORMAL, TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW5_PR5, KBC, NORMAL, TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW6_PR6, KBC, NORMAL, TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW7_PR7, KBC, NORMAL, TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW8_PS0, KBC, NORMAL, TRISTATE, INPUT),
	DEFAULT_PINMUX(KB_ROW9_PS1, KBC, NORMAL, TRISTATE, INPUT),

	/* GPIOs */
	DEFAULT_PINMUX(KB_ROW10_PS2, SDMMC2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_ROW11_PS3, SDMMC2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_ROW12_PS4, SDMMC2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_ROW13_PS5, SDMMC2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_ROW14_PS6, SDMMC2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_ROW15_PS7, SDMMC2, NORMAL, NORMAL, INPUT),

	DEFAULT_PINMUX(KB_COL0_PQ0, KBC, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_COL1_PQ1, KBC, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_COL2_PQ2, KBC, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_COL3_PQ3, KBC, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_COL4_PQ4, KBC, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_COL5_PQ5, KBC, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_COL6_PQ6, KBC, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_COL7_PQ7, KBC, NORMAL, NORMAL, INPUT),

	DEFAULT_PINMUX(PV0, RSVD1, NORMAL, NORMAL, INPUT),

	DEFAULT_PINMUX(CLK_32K_OUT_PA0, BLINK, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(SYS_CLK_REQ_PZ5, SYSCLK, NORMAL, NORMAL, INPUT),
	/* multiplexed KB_COL0 */
	DEFAULT_PINMUX(OWR, OWR, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(DAP1_FS_PN0, I2S0, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(DAP1_DIN_PN1, I2S0, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(DAP1_DOUT_PN2, I2S0, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(DAP1_SCLK_PN3, I2S0, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(CLK1_REQ_PEE2, DAP, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(CLK1_OUT_PW4, EXTPERIPH1, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(SPDIF_IN_PK6, SPDIF, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SPDIF_OUT_PK5, SPDIF, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(DAP2_FS_PA2, I2S1, NORMAL, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(DAP2_DIN_PA4, I2S1, NORMAL, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(DAP2_DOUT_PA5, I2S1, NORMAL, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(DAP2_SCLK_PA3, I2S1, NORMAL, TRISTATE, OUTPUT),

	DEFAULT_PINMUX(SPI2_CS1_N_PW2, SPI2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SPI1_MOSI_PX4, SPI1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SPI1_SCK_PX5, SPI1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SPI1_CS0_N_PX6, SPI1, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(SPI1_MISO_PX7, SPI1, NORMAL, NORMAL, INPUT),

	DEFAULT_PINMUX(PEX_L0_PRSNT_N_PDD0, RSVD2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(PEX_L0_RST_N_PDD1, RSVD2, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(PEX_L0_CLKREQ_N_PDD2, RSVD2, NORMAL, NORMAL, INPUT),

	DEFAULT_PINMUX(PEX_L1_PRSNT_N_PDD4, RSVD2, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(PEX_L1_RST_N_PDD5, RSVD2, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(PEX_L1_CLKREQ_N_PDD6, RSVD2, DOWN, TRISTATE, OUTPUT), /* NC */

	DEFAULT_PINMUX(PEX_L2_PRSNT_N_PDD7, PCIE, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(PEX_L2_RST_N_PCC6, PCIE, NORMAL, NORMAL, OUTPUT),
	DEFAULT_PINMUX(PEX_L2_CLKREQ_N_PCC7, PCIE, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(PEX_WAKE_N_PDD3, PCIE, NORMAL, NORMAL, INPUT),

	DEFAULT_PINMUX(HDMI_CEC_PEE3, CEC, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(HDMI_INT_PN7, RSVD1, NORMAL, NORMAL, INPUT),

	DEFAULT_PINMUX(GMI_IORDY_PI5, RSVD1, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_AD12_PH4, NAND, DOWN, TRISTATE, OUTPUT), /* NC */
	DEFAULT_PINMUX(GMI_AD14_PH6, NAND, DOWN, TRISTATE, OUTPUT), /* NC */

	DEFAULT_PINMUX(SPI2_SCK_PX2, GMI, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(KB_ROW8_PS0, KBC, NORMAL, NORMAL, INPUT),
};

static struct pmux_pingrp_config unused_pins_lowpower[] = {
	DEFAULT_PINMUX(GMI_WAIT_PI7, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_ADV_N_PK0, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_CLK_PK1, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_CS3_N_PK4, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_CS7_N_PI6, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD0_PG0, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD1_PG1, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD2_PG2, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD3_PG3, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD4_PG4, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD5_PG5, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD6_PG6, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD7_PG7, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD9_PH1, PWM1, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD11_PH3, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_AD13_PH5, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_WR_N_PI0, NAND, DOWN, TRISTATE, OUTPUT),
	DEFAULT_PINMUX(GMI_OE_N_PI1, NAND, NORMAL, NORMAL, INPUT),
	DEFAULT_PINMUX(GMI_DQS_PI2, NAND, DOWN, TRISTATE, OUTPUT),
};

static struct pmux_drvgrp_config apalis_t30_padctrl[] = {
	/* (_drvgrp, _slwf, _slwr, _drvup, _drvdn, _lpmd, _schmt, _hsm) */
	DEFAULT_PADCFG(SDIO1, SDIOCFG_DRVUP_SLWF, SDIOCFG_DRVDN_SLWR, \
		SDIOCFG_DRVUP, SDIOCFG_DRVDN, NONE, DISABLE, DISABLE),
};
#endif	/* _PINMUX_CONFIG_APALIS_T30_H_ */
