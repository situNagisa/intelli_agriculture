#pragma once

#define NGS_SYSTEM_IS_ESP true
#include "./ia.h"
#include "./ia.hpp"

void test_screen()
{
	auto screen = ia::detail::factory::create_screen();
	ngs::uint16_ptr demo_buffer = new ngs::uint16[128ull * 160]();// create_demo_buffer();
	std::memset(demo_buffer, 0x80, 128ull * 160 * 2ull);
	screen->show_picture(demo_buffer, 0, 0, 128, 160);
}

void test_keyboard()
{
	auto keyboard = ia::detail::factory::create_keyboard();
	auto print_key = [&kb = *keyboard](ia::api::hw::keyboard_code code)
		{
			if (!kb.is_pressed(code))
				return;
			//if (kb._state[static_cast<size_t>(code)] != kb.threshold)
			//	NGS_LOGFL(info, "key %d is pressed, state = %d", code, kb._state[static_cast<size_t>(code)]);
			if (kb.is_raised(code))
				NGS_LOGFL(info, "raised!");
		};
	while (true)
	{
		keyboard->update();
		print_key(ia::api::hw::keyboard_code::up);
		print_key(ia::api::hw::keyboard_code::down);
		print_key(ia::api::hw::keyboard_code::select);
		print_key(ia::api::hw::keyboard_code::back);
	}
}

void test_photosensor()
{
	auto photosensor = ia::detail::factory::create_photosensor();
	bool is_dark = false;
	while (true)
	{
		if (photosensor->get() != is_dark)
		{
			is_dark = photosensor->get();
			NGS_LOGFL(info, "photosensor get = %d", is_dark);
		}
	}
}

NGS_HPP_INLINE void ia_main()
{
	test_screen();
	test_photosensor();

}