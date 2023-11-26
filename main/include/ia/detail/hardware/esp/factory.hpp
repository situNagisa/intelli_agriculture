// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile
#pragma once

#include "./defined.h"
#include "../../factory.h"
#include "./config.h"
#include "./lcd.h"
#include "./keyboard.h"
#include "./flashlight.h"
#include "./ldr.h"
#include "./motor.h"
#include "./temperature_controller.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE lcd* factory::create_screen()
{
	return new lcd(
		IA_CONFIG_LCD_SCLK, IA_CONFIG_LCD_SDA, IA_CONFIG_LCD_CS, IA_CONFIG_LCD_DC, IA_CONFIG_LCD_RST, IA_CONFIG_LCD_WIDTH, IA_CONFIG_LCD_HEIGHT
	);
}

NGS_HPP_INLINE keyboard* factory::create_keyboard()
{
	return new keyboard(
		IA_CONFIG_KEYBOARD_UP, IA_CONFIG_KEYBOARD_DOWN, IA_CONFIG_KEYBOARD_SELECT, IA_CONFIG_KEYBOARD_BACK
	);
}

NGS_HPP_INLINE ldr* factory::create_photosensor()
{
	return new ldr(IA_CONFIG_LDR_OD);
}


NGS_HPP_INLINE dht* factory::create_temperature()
{
	return new dht(IA_CONFIG_DHT);
}

NGS_HPP_INLINE flashlight* factory::create_flashlight()
{
	return new flashlight(IA_CONFIG_FLASHLIGHT);
}

NGS_HPP_INLINE motor* factory::create_motor()
{
	return new motor(IA_CONFIG_MOTOR);
}

NGS_HPP_INLINE temperature_controller* factory::create_temperature_controller()
{
	return new temperature_controller(IA_CONFIG_TEMPERATURE_CONTROLLER);
}

IA_DETAIL_END
