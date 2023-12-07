#pragma once

#include "../defined.h"

#define IA_API_EMB_BEGIN IA_API_BEGIN inline namespace embedded {
#define IA_API_EMB_END } IA_API_END

IA_API_EMB_BEGIN

#if defined(NGS_SYSTEM_IS_ESP)

using ngs::embedded::io::pin_t;

using i2c_master = ngs::os_api::esp::io::bus::i2c_master;
using i2c_slave = ngs::os_api::esp::io::bus::i2c_slave;
using i2c_message = ngs::embedded::io::i2c::message;
using namespace ngs::embedded::io::i2c::modes;

using ngs::embedded::io::frequency_t;

using spi_master = ngs::os_api::esp::io::bus::spi_master;
using spi_device = ngs::os_api::esp::io::bus::spi_device;
using spi_slave = ngs::embedded::io::spi::slave;
using namespace ngs::embedded::io::spi::modes;

using ngs::os_api::esp::io::gpio;
using namespace ngs::embedded::io::gpio::modes;

#else

using ngs::embedded::io::pin_t;

using i2c_master = ngs::embedded::io::i2c::master;
using i2c_slave = ngs::embedded::io::i2c::slave;
using i2c_message = ngs::embedded::io::i2c::message;
using namespace ngs::embedded::io::i2c::modes;

using ngs::embedded::io::frequency_t;

using spi_master = ngs::embedded::io::spi::master;
using spi_device = ngs::embedded::io::spi::device;
using spi_slave = ngs::embedded::io::spi::slave;
using namespace ngs::embedded::io::spi::modes;

using ngs::embedded::io::gpio::gpio;
using namespace ngs::embedded::io::gpio::modes;

#endif

IA_API_EMB_END