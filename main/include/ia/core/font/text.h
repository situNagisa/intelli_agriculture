#pragma once

#include "./defined.h"
#include "./font.h"
#include "../transformer.h"

IA_CORE_BEGIN

struct text_field
{
	NGS_MPL_ENVIRON_BEGIN(text_field);
public:
	text_field() = default;

	text_field(::std::string_view text)
	{
		set_text(text);
	}

	void set_text(::std::string_view text)
	{
		_text = text;
		update();
	}
	void update()
	{
		transform.size.x = _text.size() * (default_font.size.width + gap.x) - gap.x;
		transform.size.y = default_font.size.height;
	}

	color_t get_pixel(size_t x_, size_t y_)const
	{
		auto w = default_font.size.width + gap.x;
		auto ix = x_ / w;

		const auto x = x_ - ix * w;
		const auto y = y_;

		if (x >= default_font.size.width)
			return color_alpha;
		if (y >= default_font.size.height)
			return color_alpha;

		return default_font.get_pixel(_text[ix], x, y);
	}

	transformer transform{};

	struct
	{
		size_t x = 0;
		size_t y = 0;
	}gap{};

	::std::pair<size_t, size_t> size()const
	{
		return { _text.size() * (default_font.size.width + gap.x) - gap.x, default_font.size.height };
	}
private:
	::std::string _text{};
};

IA_CORE_END