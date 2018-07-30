
/*
 * isp_platform_drv.h for isp reg config
 *
 * Copyright (c) 2017 by Allwinnertech Co., Ltd.  http://www.allwinnertech.com
 *
 * Authors:  Zhao Wei <zhaowei@allwinnertech.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef _ISP_PLATFORM_DRV_H_
#define _ISP_PLATFORM_DRV_H_
#include <linux/string.h>
#include "bsp_isp_comm.h"

struct isp_bsp_fun_array {

	void (*map_reg_addr) (unsigned long, unsigned long);
	void (*map_load_dram_addr) (unsigned long, unsigned long);
	void (*map_saved_dram_addr) (unsigned long, unsigned long);
	void (*isp_enable) (unsigned long, int);
	void (*isp_ch_enable) (unsigned long, int, int);
	void (*isp_wdr_ch_seq) (unsigned long, int);
	void (*isp_set_para_ready) (unsigned long, enum ready_flag);
	unsigned int (*isp_get_para_ready) (unsigned long);
	void (*isp_capture_start) (unsigned long);
	void (*isp_capture_stop) (unsigned long);
	void (*isp_irq_enable) (unsigned long, unsigned int);
	void (*isp_irq_disable) (unsigned long, unsigned int);
	unsigned int (*isp_get_irq_status) (unsigned long, unsigned int);
	void (*isp_clr_irq_status) (unsigned long, unsigned int);
	void (*isp_debug_output_cfg) (unsigned long, int, int);
	int (*isp_int_get_enable) (unsigned long);
	void (*isp_set_line_int_num) (unsigned long, unsigned int);
	void (*isp_set_last_blank_cycle) (unsigned long, unsigned int);
	void (*isp_set_speed_mode) (unsigned long, unsigned int);
	void (*isp_set_load_addr) (unsigned long, unsigned long);
	void (*isp_set_saved_addr) (unsigned long, unsigned long);
	void (*isp_set_table_addr) (unsigned long, enum isp_input_tables, unsigned long);
	void (*isp_set_statistics_addr) (unsigned long, unsigned long);
	void (*isp_channel_enable) (unsigned long, enum isp_channel);
	void (*isp_update_table) (unsigned long, unsigned short);
	unsigned int (*isp_get_isp_ver)(unsigned long, unsigned int *, unsigned int *);
	void (*isp_module_enable) (unsigned long, unsigned int);
	void (*isp_module_disable) (unsigned long, unsigned int);
	void (*isp_set_wdr_mode) (unsigned long, unsigned int);
	void (*isp_set_input_fmt) (unsigned long, unsigned int);
	void (*isp_set_size) (unsigned long, struct isp_size *, struct isp_size *, struct coor *);
	unsigned int (*isp_load_update_flag)(unsigned long);
};

struct isp_platform_drv {
	int platform_id;
	struct isp_bsp_fun_array *fun_array;
};

int isp_platform_register(struct isp_platform_drv *isp_drv);

int isp_platform_init(unsigned int platform_id);

struct isp_platform_drv *isp_get_driver(void);


#endif	/*_ISP_PLATFORM_DRV_H_*/