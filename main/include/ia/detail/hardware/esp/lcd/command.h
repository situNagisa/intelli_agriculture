#pragma once

#include "../defined.h"

IA_DETAIL_BEGIN

enum class st_command : ngs::byte
{
	nop = 0x00,
	reset = 0x01,
	read_id = 0x04,
	read_status = 0x09,
	read_power_mode = 0x0A,
	read_madctl = 0x0B,
	read_pixel_format = 0x0C,
	read_image_format = 0x0D,
	read_signal_mode = 0x0E,
	read_self_diagnostic = 0x0F,
	sleep_in = 0x10,
	sleep_out = 0x11,
	partial_mode_on = 0x12,
	normal_display_mode_on = 0x13,
	inversion_display_off = 0x20,
	inversion_display_on = 0x21,
	gamma_set = 0x26,
	display_off = 0x28,
	display_on = 0x29,
	column_address_set = 0x2A,
	page_address_set = 0x2B,
	memory_write = 0x2C,
	color_set = 0x2D,
	memory_read = 0x2E,
	partial_area = 0x30,
	vertical_scrolling_definition = 0x33,
	tearing_effect_line_off = 0x34,
	tearing_effect_line_on = 0x35,
	memory_access_control = 0x36,
	vertical_scrolling_start_address = 0x37,
	idle_mode_off = 0x38,
	idle_mode_on = 0x39,
	pixel_format_set = 0x3A,
	write_memory_continue = 0x3C,
	read_memory_continue = 0x3E,
	set_tear_scanline = 0x44,
	get_scanline = 0x45,
	write_display_brightness = 0x51,
	read_display_brightness = 0x52,
	write_ctrl_display = 0x53,
	read_ctrl_display = 0x54,
	write_content_adaptive_brightness_control = 0x55,
	read_content_adaptive_brightness_control = 0x56,
	write_cabc_minimum_brightness = 0x5E,
	read_cabc_minimum_brightness = 0x5F,
	read_id1 = 0xDA,
	read_id2 = 0xDB,
	read_id3 = 0xDC,

	// extended command
	interface_pixel_format = 0xB0,
	read_memory_access_control = 0xB4,
	write_memory_access_control = 0xB6,
	read_content_adaptive_brightness_control2 = 0xB7,
	read_display_id = 0xBF,
	positive_gamma_correction = 0xE0,
	negative_gamma_correction = 0xE1,
	digital_gamma_control1 = 0xE2,
	digital_gamma_control2 = 0xE3,
	driver_timing_control_a = 0xE8,
	driver_timing_control_b = 0xEA,
	enable_3_gamma_control = 0xF2,
	interface_control = 0xF6,
	pump_ratio_control = 0xF7,

	// power control
	power_control1 = 0xC0,
	power_control2 = 0xC1,
	power_control3 = 0xC2,
	power_control4 = 0xC3,
	power_control5 = 0xC4,
	vcom_control1 = 0xC5,
	vcom_control2 = 0xC7,
	power_controlA = 0xCB,
	power_controlB = 0xCF,

	// panel driving
	positive_voltage_gamma_control = 0xD0,
	negative_voltage_gamma_control = 0xD1,
	source_driver_direction_control = 0xD6,
	gate_driver_direction_control = 0xD7,
	gate_on_timing_adjustment = 0xE3,
	power_control6 = 0xFC,

	// panel status
	read_ddb_start = 0xA1,
	read_ddb_continue = 0xA8,

	// panel extended
	read_gmct_vcom_adjust = 0xE9,
	positive_gamma_correction2 = 0xEC,
	negative_gamma_correction2 = 0xED,
	digital_gamma_control3 = 0xEE,
};

IA_DETAIL_END