#pragma once

#include "./ia.h"
#include "./ia.hpp"

inline constexpr std::array<ngs::uint16, 128 * 160> demo_buffer = [] {
	std::array<ngs::uint16, 128 * 160> buffer{};
	for (auto& pixel : buffer)
	{
		pixel = 0x0000;
	}
	return buffer;
	}();


	NGS_HPP_INLINE void ia_main()
	{
		NGS_LOGL(info, "hello world");

		auto screen = ia::detail::factory::create_screen();
		
		screen->show_picture(demo_buffer.data(), 0, 0, 128, 160);
		
		while (true);
	}