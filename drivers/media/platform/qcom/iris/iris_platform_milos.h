/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __IRIS_PLATFORM_MILOS_H__
#define __IRIS_PLATFORM_MILOS_H__

static const char * const milos_opp_pd_table[] = { "cx", "mx" };

static const struct icc_info milos_icc_table[] = {
	{ "cpu-cfg",    1000, 1000     },
	{ "video-mem",  1000, 10000000 },
};

static struct platform_inst_caps platform_inst_cap_milos = {
	.min_frame_width = 96,
	.max_frame_width = 4096,
	.min_frame_height = 96,
	.max_frame_height = 4096,
	.max_mbpf = (4096 * 2176) / 256,
	.mb_cycles_vpp = 200,
	.mb_cycles_fw = 326389,
	.mb_cycles_fw_vpp = 44156,
	.num_comv = 0,
	.max_frame_rate = MAXIMUM_FPS,
	.max_operating_rate = MAXIMUM_FPS,
};

static struct ubwc_config_data ubwc_config_milos = {
	.max_channels = 8,
	.mal_length = 32,
	.highest_bank_bit = 15,
	.bank_swzl_level = 0,
	.bank_swz2_level = 1,
	.bank_swz3_level = 1,
	.bank_spreading = 1,
};

#endif
