#pragma once

#include"./dht.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE dht::dht(ngs::embedded::io::pin_t gpio_num)
{
	ngs::os_api::esp::io::gpio_config config{};
	config.set_io(ngs::embedded::io::gpio::modes::io::input_output);
	config.set_pull(ngs::embedded::io::gpio::modes::pull::floating);
	NGS_ASSERT(_gpio.open(gpio_num, config));
}

NGS_HPP_INLINE dht::_aht10_write_init() {

	using namespace std::chrono_literals;
	
	aht10.open(1, 2, 3);
	aht10.set_ack(::ngs::embedded::io::bus::i2c::modes::ack::any);

	::ngs::byte cmd = 0X70;
	aht10.write(&cmd, 1);

	::ngs::byte cmd1 = 0XE1;
	aht10.write(&cmd1, 1);

	::ngs::byte cmd2 = 0X08;
	aht10.write(&cmd2, 1);

	::ngs::byte cmd3 = 0X00;
	aht10.write(&cmd3, 1);

	aht10.close();
	std::this_thread::sleep_for(40ms);
}

NGS_HPP_INLINE dht::_aht10_write_reset() {

	using namespace std::chrono_literals;

	aht10.open(1, 2, 3);
	aht10.set_ack(::ngs::embedded::io::bus::i2c::modes::ack::any);

	::ngs::byte cmd1 = 0X70;
	aht10.write(&cmd1, 1);

	::ngs::byte cmd2 = 0XBA;
	aht10.write(&cmd2, 1);

	aht10.close();
	std::this_thread::sleep_for(20ms);
}

NGS_HPP_INLINE std::pair<ngs::float32,ngs::float32> dht::_aht10_read_humi_temp() {
	using namespace std::chrono_literals;
	extern ngs::byte ACK;

	aht10.open(1, 2, 3);
	aht10.set_ack(::ngs::embedded::io::bus::i2c::modes::ack::any);

	::ngs::byte cmd1 = 0X70;
	aht10.write(&cmd1, 1);

	::ngs::byte cmd2 = 0XAC;
	aht10.write(&cmd2, 1);

	::ngs::byte cmd3 = 0X33;
	aht10.write(&cmd3, 1);

	::ngs::byte cmd4 = 0X00;
	aht10.write(&cmd4, 1);
	
	aht10.close();
	std::this_thread::sleep_for(80ms);

	aht10.open(1, 2, 3);

	::ngs::byte cmd1 = 0X71;
	aht10.write(&cmd1, 1);
	::ngs::byte cmd2 = 0000;
	ACK = aht10.read(&cmd2,1);
	
	aht10.set_ack(::ngs::embedded::io::bus::i2c::modes::ack::last_no_ack);
	::ngs::byte data[4]{};
	aht10.read(data, 4);
	aht10.close();

	::ngs::byte humi, temp;
	humi = (data[0] << 12) | (data[1] << 4) | (data[2] >> 4);
	temp = ((data[2] & 0X0F) << 16) | (data[3] << 8) | (data[4]);

	return { static_cast<ngs::float32>(0),static_cast<ngs::float32>(0) };

	aht10.close();

}

IA_DETAIL_END