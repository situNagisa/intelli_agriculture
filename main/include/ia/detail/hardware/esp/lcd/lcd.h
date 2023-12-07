#pragma once

#include "../defined.h"
#include "./command.h"
#include "../config.h"

IA_DETAIL_BEGIN

enum class dc_mode
{
	cmd,
	data
};

struct NGS_DLL_API lcd : api::hw::screen
{
protected:
	using self_type = lcd;
public:

	struct user_data
	{
		dc_mode mode;
		self_type* self;
	};
public:

	lcd(
		api::pin_t sclk, api::pin_t mosi, api::pin_t cs, api::pin_t dc_, api::pin_t rst_,
		size_t width, size_t height, size_t pages
	);
	virtual ~lcd() override;

	ngs::uint32 get_id();

	virtual void flush() override;
	virtual void show_picture(ngs::void_ptr_cst buffer) override;
	void reset();

	void cmd(st_command cmd, bool keep_cs_active = false);
	void data(ngs::void_ptr_cst data, size_t size);

	void set_draw_range(size_t x, size_t y, size_t width, size_t height);
	void write_memory(ngs::void_ptr_cst data, size_t size);
	void write_memory(::std::ranges::contiguous_range auto&& range)
	{
		self_type::write_memory(::std::ranges::data(NGS_PP_PERFECT_FORWARD(range)), ::std::ranges::size(NGS_PP_PERFECT_FORWARD(range)));
	}
private:
	void _initialize();
	void _read_data(st_command command, ngs::void_ptr buffer, size_t size);
public:
	api::spi_master master{};
	api::spi_device device{};
	api::gpio dc{};
	api::gpio rst{};

	struct
	{
		size_t lines = 0;
		size_t width = 0;
		size_t height = 0;

		auto size()const { return width * height; }
		auto page_size()const { return width * lines; }
		auto block_size()const { return height / lines; }

		struct range_type
		{
			size_t x = 0;
			size_t y = 0;
			size_t width = 0;
			size_t height = 0;
		};
		range_type range(size_t index)const
		{
			return { 0, index * lines, width, lines };
		}
	}page{};

private:
	user_data _cmd{ dc_mode::cmd,this };
	user_data _data{ dc_mode::data,this };

};

IA_DETAIL_END