#pragma once

#define NGS_SYSTEM_IS_ESP true
#include "./ia.h"
#include "./ia.hpp"

NGS_HPP_INLINE void ia_main()
{
	using namespace ia::detail;
	NGS_LOGL(info, "hello world");

	auto screen = ia::detail::factory::create_screen();
	ngs::uint16_ptr demo_buffer = new ngs::uint16[128ull * 160](0xFFFF);// create_demo_buffer();
	screen->show_picture(demo_buffer, 0, 0, 128, 160);
}