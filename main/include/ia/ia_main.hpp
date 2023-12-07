#pragma once

#define NGS_SYSTEM_IS_ESP true
#include "./ia.h"
#include "./ia.hpp"

NGS_HPP_INLINE void ia_main()
{
	using namespace std::chrono_literals;
	//sensor
	std::unique_ptr<ia::api::hw::sensors::temperature> temperature(ia::detail::factory::create_temperature());
	//std::unique_ptr<ia::api::hw::sensors::humidity> humidity(ia::detail::factory::create_humidity());
	std::unique_ptr<ia::api::hw::sensors::photosensor> light(ia::detail::factory::create_photosensor());

	std::unique_ptr<ia::api::hw::fan> fan(ia::detail::factory::create_motor());
	std::unique_ptr<ia::api::hw::flashlight> led(ia::detail::factory::create_flashlight());
	std::unique_ptr<ia::api::hw::temperature_controller> temperature_controller(ia::detail::factory::create_temperature_controller());

	std::unique_ptr<ia::api::hw::screen> screen(ia::detail::factory::create_screen());

	ia::core::framebuffer framebuffer(IA_CONFIG_LCD_WIDTH, IA_CONFIG_LCD_HEIGHT);
	ia::core::renderer renderer(framebuffer);

	ia::core::text_field text_field{};
	text_field.gap.x = 3;
	text_field.transform.position.x = 50;
	text_field.transform.position.y = 50;
	text_field.set_text("hello");

	while (true)
	{
		//sensor
		auto&& temperature_value = temperature->get();
		//ia::api::hw::sensors::humidity::value_type humidity_value = humidity->get();
		auto&& light_value = light->get();

		if (temperature_value < 20)
		{
			temperature_controller->on();
		}
		else
		{
			temperature_controller->off();
		}

		if (light_value < 100)
		{
			led->on();
		}
		else
		{
			led->off();
		}
		renderer.flush(ia::color_constant_t::black);

		renderer.render(text_field);

		screen->show_picture(framebuffer.data().data());

		while (true);
	}
}