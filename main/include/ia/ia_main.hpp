#pragma once

#define NGS_SYSTEM_IS_ESP true
#include "./ia.h"
#include "./ia.hpp"

NGS_HPP_INLINE void ia_main()
{
	using namespace std::chrono_literals;
	//sensor
	std::unique_ptr<ia::detail::aht> temperature(ia::detail::factory::create_temperature());
	//std::unique_ptr<ia::api::hw::sensors::humidity> humidity(ia::detail::factory::create_humidity());
	std::unique_ptr<ia::api::hw::sensors::photosensor> light(ia::detail::factory::create_photosensor());

	std::unique_ptr<ia::api::hw::fan> fan(ia::detail::factory::create_motor());
	std::unique_ptr<ia::api::hw::flashlight> led(ia::detail::factory::create_flashlight());
	std::unique_ptr<ia::api::hw::temperature_controller> temperature_controller(ia::detail::factory::create_temperature_controller());

	std::unique_ptr<ia::api::hw::screen> screen(ia::detail::factory::create_screen());

	ia::core::framebuffer framebuffer(IA_CONFIG_LCD_WIDTH, IA_CONFIG_LCD_HEIGHT);
	ia::core::renderer renderer(framebuffer);

	ia::core::text_field t_text{};
	t_text.gap.x = 3;
	t_text.transform.position.x = 20;
	t_text.transform.position.y = 20;
	auto h_text = t_text;
	h_text.transform.position.y += 20;

	while (true)
	{
		//sensor
		auto [h, t] = temperature->get();
		//ia::api::hw::sensors::humidity::value_type humidity_value = humidity->get();
		auto light_value = light->get();

		t_text.set_text(::ngs::format("T: %2.2f", t));
		h_text.set_text(::ngs::format("H: %0.2f", h));

		if (t < 20)
		{
			temperature_controller->on();
		}
		else
		{
			temperature_controller->off();
		}

		if (h > 0.4)
		{
			fan->on();
		}
		else
		{
			fan->off();
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

		renderer.render(t_text);
		renderer.render(h_text);

		screen->show_picture(framebuffer.data().data());

		::std::this_thread::sleep_for(1s);
	}
}