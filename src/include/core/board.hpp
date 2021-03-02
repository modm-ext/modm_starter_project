#ifndef BOARD_HPP
#define BoARD_HPP

#include <modm/platform.hpp>

using Led = GpioInverted<GpioOutputC13>;
using Leds = SoftwareGpioPort<Led>;

using Button = GpioInverted<GpioInputA0>;

using W5500_reset = GpioOutputB9;
using W5500_int = GpioInputB4;
using W5500_nss = GpioOutputB1;
using W5500_sck = GpioOutputB0;
using W5500_miso = GpioInputA12;
using W5500_mosi = GpioOutputA8;

using Spi1_nss = GpioOutputA4;
using Spi1_sck = GpioOutputA5;
using Spi1_miso = GpioInputA6;
using Spi1_mosi = GpioOutputA7;

using I2c1_scl = GpioOutputB6;
using I2c1_sda = GpioB7;

using Uart1_tx = GpioOutputA9;
using Uart1_rx = GpioInputA10;

#endif