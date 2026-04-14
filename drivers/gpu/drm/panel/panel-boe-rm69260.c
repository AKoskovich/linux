// SPDX-License-Identifier: GPL-2.0-only
/*
 * Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree.
 * Copyright (c) 2026 Alexander Koskovich <akoskovich@pm.me>
 */

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <drm/display/drm_dsc.h>
#include <drm/display/drm_dsc_helper.h>
#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct boe_rm69260 {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct drm_dsc_config dsc;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data boe_rm69260_supplies[] = {
	{ .supply = "dvdd" },
	{ .supply = "vci" },
	{ .supply = "vddio" },
};

static inline
struct boe_rm69260 *to_boe_rm69260(struct drm_panel *panel)
{
	return container_of_const(panel, struct boe_rm69260, panel);
}

static void boe_rm69260_reset(struct boe_rm69260 *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
}

static int boe_rm69260_on(struct boe_rm69260 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xa0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x06, 0x76);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7c, 0x1f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x42);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x78, 0x15);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xd4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x40, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x42, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xf7);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x80, 0x06);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x83, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xa1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x74, 0x72);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3, 0x83);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc4, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x3f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x67);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd0, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xa4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x01, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x9c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x12, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbd, 0xbb);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbb, 0xbb);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc, 0xbb);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x23, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x9a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x64, 0xe0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbf, 0x0e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc0, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x9b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x52, 0x27);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x14, 0x32);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x46);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x60, 0x06);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x40);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x3a, 0x0c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x3b, 0x30);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x37, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfa, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc1, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x35, 0x00);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 105);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_usleep_range(&dsi_ctx, 10000, 11000);

	return dsi_ctx.accum_err;
}

static int boe_rm69260_off(struct boe_rm69260 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x00);
	mipi_dsi_msleep(&dsi_ctx, 35);
	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 80);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 32);

	return dsi_ctx.accum_err;
}

static int boe_rm69260_prepare(struct drm_panel *panel)
{
	struct boe_rm69260 *ctx = to_boe_rm69260(panel);
	struct device *dev = &ctx->dsi->dev;
	struct drm_dsc_picture_parameter_set pps;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(boe_rm69260_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	boe_rm69260_reset(ctx);

	ret = boe_rm69260_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(boe_rm69260_supplies), ctx->supplies);
		return ret;
	}

	drm_dsc_pps_payload_pack(&pps, &ctx->dsc);

	ret = mipi_dsi_picture_parameter_set(ctx->dsi, &pps);
	if (ret < 0) {
		dev_err(panel->dev, "failed to transmit PPS: %d\n", ret);
		return ret;
	}

	ret = mipi_dsi_compression_mode(ctx->dsi, true);
	if (ret < 0) {
		dev_err(dev, "failed to enable compression mode: %d\n", ret);
		return ret;
	}

	msleep(28); /* TODO: Is this panel-dependent? */

	return 0;
}

static int boe_rm69260_unprepare(struct drm_panel *panel)
{
	struct boe_rm69260 *ctx = to_boe_rm69260(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = boe_rm69260_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(boe_rm69260_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode boe_rm69260_mode = {
	.clock = (1260 + 204 + 4 + 12) * (2800 + 88 + 2 + 62) * 120 / 1000,
	.hdisplay = 1260,
	.hsync_start = 1260 + 204,
	.hsync_end = 1260 + 204 + 4,
	.htotal = 1260 + 204 + 4 + 12,
	.vdisplay = 2800,
	.vsync_start = 2800 + 88,
	.vsync_end = 2800 + 88 + 2,
	.vtotal = 2800 + 88 + 2 + 62,
	.width_mm = 71,
	.height_mm = 158,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int boe_rm69260_get_modes(struct drm_panel *panel,
						struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &boe_rm69260_mode);
}

static const struct drm_panel_funcs boe_rm69260_panel_funcs = {
	.prepare = boe_rm69260_prepare,
	.unprepare = boe_rm69260_unprepare,
	.get_modes = boe_rm69260_get_modes,
};

static int boe_rm69260_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

static int boe_rm69260_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness;
}

static const struct backlight_ops boe_rm69260_bl_ops = {
	.update_status = boe_rm69260_bl_update_status,
	.get_brightness = boe_rm69260_bl_get_brightness,
};

static struct backlight_device *
boe_rm69260_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 11378,
		.max_brightness = 14063, /* 16383 is HBM max */
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &boe_rm69260_bl_ops, &props);
}

static int boe_rm69260_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct boe_rm69260 *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct boe_rm69260, panel,
				   &boe_rm69260_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(boe_rm69260_supplies),
					    boe_rm69260_supplies,
					    &ctx->supplies);
	if (ret < 0)
		return ret;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_NO_EOT_PACKET |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM |
			  MIPI_DSI_MODE_DSC_ALL_SLICES_IN_PKT;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = boe_rm69260_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	/* This panel only supports DSC; unconditionally enable it */
	dsi->dsc = &ctx->dsc;

	ctx->dsc.dsc_version_major = 1;
	ctx->dsc.dsc_version_minor = 1;

	ctx->dsc.slice_height = 8;
	ctx->dsc.slice_width = 630;

	ctx->dsc.slice_count = 1260 / ctx->dsc.slice_width;
	ctx->dsc.bits_per_component = 8;
	ctx->dsc.bits_per_pixel = 8 << 4; /* 4 fractional bits */
	ctx->dsc.block_pred_enable = true;

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void boe_rm69260_remove(struct mipi_dsi_device *dsi)
{
	struct boe_rm69260 *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id boe_rm69260_of_match[] = {
	{ .compatible = "boe,rm69260" },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, boe_rm69260_of_match);

static struct mipi_dsi_driver boe_rm69260_driver = {
	.probe = boe_rm69260_probe,
	.remove = boe_rm69260_remove,
	.driver = {
		.name = "panel-boe-rm69260",
		.of_match_table = boe_rm69260_of_match,
	},
};
module_mipi_dsi_driver(boe_rm69260_driver);

MODULE_AUTHOR("Alexander Koskovich <akoskovich@pm.me>");
MODULE_DESCRIPTION("BOE RM69260 MIPI-DSI OLED panel");
MODULE_LICENSE("GPL");
