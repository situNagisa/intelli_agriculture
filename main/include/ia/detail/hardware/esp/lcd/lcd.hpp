#pragma once

#include "./lcd.h"
#include "./command.h"

IA_DETAIL_BEGIN

struct lcd_init_cmd_t {
	uint8_t cmd;
	uint8_t data[16];
	uint8_t databytes; //No of data in data; bit 7 = delay after set; 0xFF = end of cmds.
};

inline constexpr lcd_init_cmd_t st_init_cmds[] = {
	/* Memory Data Access Control, MX=MV=1, MY=ML=MH=0, RGB=0 */
	{0x36, {(1 << 5) | (1 << 6)}, 1},
	/* Interface Pixel Format, 16bits/pixel for RGB/MCU interface */
	{0x3A, {0x55}, 1},
	/* Porch Setting */
	{0xB2, {0x0c, 0x0c, 0x00, 0x33, 0x33}, 5},
	/* Gate Control, Vgh=13.65V, Vgl=-10.43V */
	{0xB7, {0x45}, 1},
	/* VCOM Setting, VCOM=1.175V */
	{0xBB, {0x2B}, 1},
	/* LCM Control, XOR: BGR, MX, MH */
	{0xC0, {0x2C}, 1},
	/* VDV and VRH Command Enable, enable=1 */
	{0xC2, {0x01, 0xff}, 2},
	/* VRH Set, Vap=4.4+... */
	{0xC3, {0x11}, 1},
	/* VDV Set, VDV=0 */
	{0xC4, {0x20}, 1},
	/* Frame Rate Control, 60Hz, inversion=0 */
	{0xC6, {0x0f}, 1},
	/* Power Control 1, AVDD=6.8V, AVCL=-4.8V, VDDS=2.3V */
	{0xD0, {0xA4, 0xA1}, 1},
	/* Positive Voltage Gamma Control */
	{0xE0, {0xD0, 0x00, 0x05, 0x0E, 0x15, 0x0D, 0x37, 0x43, 0x47, 0x09, 0x15, 0x12, 0x16, 0x19}, 14},
	/* Negative Voltage Gamma Control */
	{0xE1, {0xD0, 0x00, 0x05, 0x0D, 0x0C, 0x06, 0x2D, 0x44, 0x40, 0x0E, 0x1C, 0x18, 0x16, 0x19}, 14},
	/* Sleep Out */
	{0x11, {0}, 0x80},
	/* Display On */
	{0x29, {0}, 0x80},
	{0, {0}, 0xff}
};

NGS_HPP_GLOBAL_STATIC void pre_transfer_callback(spi_transaction_t* t)
{
	auto& data = *static_cast<lcd::user_data*>(t->user);
	data.self->dc.set(static_cast<bool>(data.mode));
	//NGS_LOGFL(debug, "mode = %d", data.mode);
}

NGS_HPP_INLINE lcd::lcd(api::pin_t sclk, api::pin_t mosi, api::pin_t cs, api::pin_t dc_, api::pin_t rst_, size_t width, size_t height)
{
	{
		spi_bus_config_t config{
			.mosi_io_num = mosi,
			.miso_io_num = ngs::embedded::io::invalid_pin,
			.sclk_io_num = sclk,
			.quadwp_io_num = ngs::embedded::io::invalid_pin,
			.quadhd_io_num = ngs::embedded::io::invalid_pin,
			.max_transfer_sz = static_cast<int>(width * height * 2) + 8
		};

		NGS_ASSERT(master.open(config));
		NGS_LOGL(info, "spi bus opened successfully!");
	}
	{
		device.set_polarity(ngs::embedded::io::bus::spi::modes::polarity::low);
		device.set_phase(ngs::embedded::io::bus::spi::modes::phase::first);
		device.set_cs(cs);
		device.pre_cb = pre_transfer_callback;
		device.queue_size = 7;
		device.clock_speed_hz = 26 * 1000 * 1000;

		master.add_device(device);
		master.select(device);
		NGS_LOGL(info, "spi device opened successfully!");
	}
	{
		ngs::os_api::esp::io::gpio_config config{};
		config.set_io(ngs::embedded::io::gpio::modes::io::output);
		config.set_pull(ngs::embedded::io::gpio::modes::pull::up);

		NGS_ASSERT(dc.open(dc_, config));
		NGS_ASSERT(rst.open(rst_, config));
		NGS_LOGL(info, "gpio opened successfully!");
	}

	_initialize();
}

NGS_HPP_INLINE lcd::~lcd()
{
	master.close();
	dc.close();
	rst.close();
}

NGS_HPP_INLINE void lcd::flush()
{
	cmd(st_command::reset, false);
}

NGS_HPP_INLINE void lcd::show_picture(ngs::void_ptr_cst buffer, size_t x, size_t y, size_t width, size_t height)
{
	using namespace std::chrono_literals;

	ngs::byte tx_data[4]{};
	auto set_range = [&tx_data](ngs::uint16 start, ngs::uint16 end)
		{
			tx_data[0] = start >> ngs::bits::bit_per_byte;
			tx_data[1] = start & 0xFF;
			tx_data[2] = end >> ngs::bits::bit_per_byte;
			tx_data[3] = end & 0xFF;
		};

	//master.lock();
	cmd(st_command::column_address_set);
	set_range(x, x + width);
	data(tx_data, 4);
	cmd(st_command::page_address_set);
	set_range(y, y + height);
	data(tx_data, 4);
	cmd(st_command::memory_write);
	data(buffer, width * height * 2);
	//master.unlock();
}

NGS_HPP_INLINE void lcd::reset()
{
	using namespace std::chrono_literals;

	rst.low();
	std::this_thread::sleep_for(100ms);
	rst.high();
	std::this_thread::sleep_for(100ms);
}

NGS_HPP_INLINE ngs::uint32 lcd::get_id()
{
	ngs::uint32 id{};
	_read_data(st_command::read_id, &id, 3);
	return id;
}

NGS_HPP_INLINE void lcd::cmd(st_command cmd, bool keep_cs_active)
{
	if (keep_cs_active)
		NGS_ASSERT(master.is_locking(), "spi bus is not locking! please call `lock()` first");

	//NGS_LOGL(debug, "cmd");
	const ngs::uint32 flags = ngs::bits::set(0, SPI_TRANS_CS_KEEP_ACTIVE, keep_cs_active);
	master.polling_transmit(cmd, &_cmd, flags);
}

NGS_HPP_INLINE void lcd::data(ngs::void_ptr_cst data, size_t size)
{
	if (!size)return;
	//NGS_LOGL(debug, "data");
	master.polling_transmit(data, size, &_data);
}

NGS_HPP_INLINE void lcd::_initialize()
{
	using namespace std::chrono_literals;

	reset();

	auto id = get_id();
	NGS_LOGFL(info, "lcd id: 0x%08x", id);

	auto&& lcd_init_cmds = st_init_cmds;

	for (auto&& [command, data, flag] : lcd_init_cmds)
	{
		if (flag == 0xFF)break;
		cmd(static_cast<st_command>(command));
		data(data, flag & 0x1F);
		if (flag & 0x80) {
			std::this_thread::sleep_for(100ms);
		}
	}

	NGS_LOGL(info, "lcd initalized successfully!");


}

NGS_HPP_INLINE void lcd::_read_data(st_command command, ngs::void_ptr buffer, size_t size)
{
	using namespace std::chrono_literals;

	master.lock();
	cmd(command, true);
	master.polling_receive(buffer, size, &_data);
	master.unlock();
}


IA_DETAIL_END
