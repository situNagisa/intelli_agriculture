#pragma once

#include "./defined.h"

IA_CORE_BEGIN

struct framebuffer
{
	NGS_MPL_ENVIRON_BEGIN(framebuffer);
public:
	framebuffer(size_t width, size_t height)
		: _width(width), _height(height)
	{
		_data = ::std::span<color_t>(new color_t[_width * _height](), _width * _height);
	}
	~framebuffer()
	{
		delete[] _data.data();
	}


	auto&& data() { return _data; }
	auto&& data()const { return _data; }

	auto&& operator()(size_t x, size_t y) { return _data[x + y * _width]; }
	auto&& operator()(size_t x, size_t y)const { return _data[x + y * _width]; }

private:
	size_t _width = 0;
	size_t _height = 0;
	::std::span<color_t> _data{};
};

IA_CORE_END
