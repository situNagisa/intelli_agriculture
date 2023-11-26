#pragma once

#include "./defined.h"

IA_DETAIL_BEGIN

struct NGS_DLL_API flashlight final : api::hw::flashlight
{
	explicit(true) flashlight(ngs::embedded::io::pin_t io)
	{
		ngs::os_api::esp::io::gpio_config config{};
		config.set_io(ngs::embedded::io::gpio::modes::io::output);
		config.set_pull(ngs::embedded::io::gpio::modes::pull::up);

		NGS_ASSERT(_io.open(io, config));

		_io.low();
	}
	virtual ~flashlight()override
	{
		if (_io.is_opened())
			_io.close();
	}

	virtual void on() override
	{
		_io.high();
		_state = true;
	}
	virtual void off() override
	{
		_io.low();
		_state = false;
	}

	virtual bool is_on() const override
	{
		return _state;
	}
private:
	api::gpio _io{};
	bool _state = false;
};

IA_DETAIL_END