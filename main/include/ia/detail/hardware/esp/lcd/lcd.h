#pragma once

#include "../defined.h"
#include "./command.h"

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
		size_t width, size_t height
	);
	virtual ~lcd() override;

	ngs::uint32 get_id();

	virtual void flush() override;
	virtual void show_picture(ngs::void_ptr_cst buffer, size_t x, size_t y, size_t width, size_t height) override;
	void reset();

	void cmd(st_command cmd, bool keep_cs_active = false);
	void data(ngs::void_ptr_cst data, size_t size);

private:
	void _initialize();
	void _read_data(st_command command, ngs::void_ptr buffer, size_t size);
public:
	api::spi_master master{};
	api::spi_device device{};
	api::gpio dc{};
	api::gpio rst{};

private:
	user_data _cmd{ dc_mode::cmd,this };
	user_data _data{ dc_mode::data,this };

};

IA_DETAIL_END