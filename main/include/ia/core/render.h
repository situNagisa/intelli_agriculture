#pragma once

#include "./defined.h"
#include "./font.h"
#include "./framebuffer.h"

IA_CORE_BEGIN

struct renderer
{
	renderer(framebuffer& framebuffer)
		: _framebuffer(&framebuffer)
	{

	}

	void flush(color_t color) const
	{
		::std::ranges::fill(_framebuffer->data(), color);
	}
	void render(const text_field& text_field) const
	{
		auto&& transformer = text_field.transform;
		NGS_LOGFL(debug, "%f,%f", transformer.size.x, transformer.size.y);
		for (size_t y = 0; y < static_cast<size_t>(transformer.size.y); ++y)
		{
			for (size_t x = 0; x < static_cast<size_t>(transformer.size.x); ++x)
			{
				auto pixel = text_field.get_pixel(x, y);
				if (pixel == color_alpha)continue;
				(*_framebuffer)(transformer.position.x + x, transformer.position.y + y) = text_field.get_pixel(x, y);
			}
		}
	}
private:
	framebuffer* _framebuffer = nullptr;
};

IA_CORE_END