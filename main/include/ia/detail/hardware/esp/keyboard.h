#pragma once

#include "./defined.h"
#include "./config.h"

IA_DETAIL_BEGIN

struct NGS_DLL_API keyboard : api::hw::keyboard
{
protected:
	using self_type = keyboard;
public:

public:

	keyboard()
	{
		ngs::os_api::esp::io::gpio_config config{};
		config.set_io(ngs::embedded::io::gpio::modes::io::input);
		config.set_pull(ngs::embedded::io::gpio::modes::pull::down);
		_up.open(IA_CONFIG_KEYBOARD_UP, config);
		_down.open(IA_CONFIG_KEYBOARD_DOWN, config);
		_select.open(IA_CONFIG_KEYBOARD_SELECT, config);
		_back.open(IA_CONFIG_KEYBOARD_BACK, config);
	}
	virtual ~keyboard() override = default;

	virtual bool is_pressed(api::hw::keyboard_code code) const override
	{
		switch (code)
		{
		case api::hw::keyboard_code::up:
			return _up.get();
		case api::hw::keyboard_code::down:
			return _down.get();
		case api::hw::keyboard_code::back:
			return _back.get();
		case api::hw::keyboard_code::select:
			return _select.get();
		}
		return false;
	}

private:
	api::gpio _up{};
	api::gpio _down{};
	api::gpio _select{};
	api::gpio _back{};
};




IA_DETAIL_END