/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuration file for the SAMA7D65EB Board.
 *
 * Copyright (C) 2023 Microchip Corporation and its subsidiaries
 *
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_SYS_AT91_SLOW_CLOCK      32768
#define CONFIG_SYS_AT91_MAIN_CLOCK      24000000 /* from 24 MHz crystal */
/* SDRAM */
#define CONFIG_SYS_SDRAM_BASE		0x60000000
#define CONFIG_SYS_SDRAM_SIZE		0x20000000

#endif
