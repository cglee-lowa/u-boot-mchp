/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuration file for the SAMA5D2 ICP Board.
 *
 * Copyright (C) 2020 Microchip Corporation
 *		      Eugen Hristev <eugen.hristev@microchip.com>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_SYS_AT91_SLOW_CLOCK      32768
#define CONFIG_SYS_AT91_MAIN_CLOCK      24000000 /* from 24 MHz crystal */

#define CONFIG_MISC_INIT_R

/* SDRAM */
#define CONFIG_SYS_SDRAM_BASE		0x60000000
#define CONFIG_SYS_SDRAM_SIZE		0x20000000

#ifdef CONFIG_SPL_BUILD
#define CONFIG_SYS_INIT_SP_ADDR		0x218000
#else
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_SDRAM_BASE + 16 * 1024 + CONFIG_SYS_MALLOC_F_LEN - \
	 GENERATED_GBL_DATA_SIZE)
#endif

#define CONFIG_SYS_LOAD_ADDR		0x62000000 /* load address */

#undef CONFIG_BOOTCOMMAND
#ifdef CONFIG_SD_BOOT
/* u-boot env in sd/mmc card */
#define FAT_ENV_INTERFACE	"mmc"
#define FAT_ENV_DEVICE_AND_PART	"0"
#define FAT_ENV_FILE		"uboot.env"
/* bootstrap + u-boot + env in sd card */
#define CONFIG_BOOTCOMMAND	"fatload mmc 0:1 0x61000000 at91-sama7g5ek.dtb; " \
				"fatload mmc 0:1 0x62000000 zImage; " \
				"bootz 0x62000000 - 0x61000000"
#undef CONFIG_BOOTARGS
#define CONFIG_BOOTARGS \
	"console=ttyS0,115200 earlycon earlyprintk=serial,ttyS0, ignore_loglevel root=/dev/mmcblk0p2 memtest=0 rootfstype=ext4 rw rootwait cma=256m"
#endif

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(4 * 1024 * 1024)

#endif