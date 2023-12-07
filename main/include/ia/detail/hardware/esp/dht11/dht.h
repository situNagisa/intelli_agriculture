#pragma once
#include"../defined.h"

IA_DETAIL_BEGIN

struct dht : api::hw::sensors::temperature
{

	ia::api::i2c_master aht10{};

	virtual api::hw::sensors::temperature_t get()  override;

private:
	void _aht10_write_init();
	void _aht10_write_reset();
	ngs::byte _aht10_read_humi_temp();

private:
	api::gpio _gpio{};
};

IA_DETAIL_END
