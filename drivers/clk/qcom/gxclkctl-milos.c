// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 */

#include <linux/platform_device.h>
#include <linux/regmap.h>

#include <dt-bindings/clock/qcom,milos-gxclkctl.h>
#include <dt-bindings/reset/qcom,milos-gxclkctl.h>

#include "common.h"
#include "gdsc.h"
#include "reset.h"

static struct gdsc gx_clkctl_gx_gdsc = {
	.gdscr = 0x4024,
	.en_rest_wait_val = 0x2,
	.en_few_wait_val = 0x2,
	.clk_dis_wait_val = 0x8,
	.resets = (unsigned int []){ GX_CLKCTL_GX_BCR },
	.reset_count = 1,
	.pd = {
		.name = "gx_clkctl_gx_gdsc",
		.power_on = gdsc_gx_do_nothing_enable,
	},
	.pwrsts = PWRSTS_OFF_ON,
	.flags = POLL_CFG_GDSCR | RETAIN_FF_ENABLE,
};

static const struct qcom_reset_map gx_clkctl_milos_resets[] = {
	[GX_CLKCTL_GX_BCR] = { 0x4020 },
};

static struct gdsc *gx_clkctl_milos_gdscs[] = {
	[GX_CLKCTL_GX_GDSC] = &gx_clkctl_gx_gdsc,
};

static u32 gx_clkctl_milos_critical_cbcrs[] = {
	0x4040, /* GPU_GX_CLKCTL_GX_GFX3D_CBCR */
	0x4008, /* GPU_GX_CLKCTL_CLK_CTL_XO_CBCR */
};

static const struct regmap_config gx_clkctl_milos_regmap_config = {
	.reg_bits = 32,
	.reg_stride = 4,
	.val_bits = 32,
	.max_register = 0x4040,
	.fast_io = true,
};

static struct qcom_cc_driver_data gx_clkctl_milos_driver_data = {
	.clk_cbcrs = gx_clkctl_milos_critical_cbcrs,
	.num_clk_cbcrs = ARRAY_SIZE(gx_clkctl_milos_critical_cbcrs),
};

static const struct qcom_cc_desc gx_clkctl_milos_desc = {
	.config = &gx_clkctl_milos_regmap_config,
	.resets = gx_clkctl_milos_resets,
	.num_resets = ARRAY_SIZE(gx_clkctl_milos_resets),
	.gdscs = gx_clkctl_milos_gdscs,
	.num_gdscs = ARRAY_SIZE(gx_clkctl_milos_gdscs),
	.driver_data = &gx_clkctl_milos_driver_data,
	.use_rpm = true,
};

static const struct of_device_id gx_clkctl_milos_match_table[] = {
	{ .compatible = "qcom,milos-gxclkctl" },
	{ }
};
MODULE_DEVICE_TABLE(of, gx_clkctl_milos_match_table);

static int gx_clkctl_milos_probe(struct platform_device *pdev)
{
	return qcom_cc_probe(pdev, &gx_clkctl_milos_desc);
}

static struct platform_driver gx_clkctl_milos_driver = {
	.probe = gx_clkctl_milos_probe,
	.driver = {
		.name = "gxclkctl-milos",
		.of_match_table = gx_clkctl_milos_match_table,
	},
};

module_platform_driver(gx_clkctl_milos_driver);

MODULE_DESCRIPTION("QTI GXCLKCTL Milos Driver");
MODULE_LICENSE("GPL");
