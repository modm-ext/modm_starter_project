#include <modm/board.hpp>
#include <modm/debug/logger.hpp>
#include <modm/architecture/interface/build_id.hpp>
#include <core/board.hpp>
#include <string>

// hdr_only_lib
#include <test/header1.h>
// shared_lib
#include <mylib.h>

modm::IODeviceWrapper<Usart1, modm::IOBuffer::BlockIfFull> device;

modm::log::Logger modm::log::debug(device);
modm::log::Logger modm::log::info(device);
modm::log::Logger modm::log::warning(device);
modm::log::Logger modm::log::error(device);


int main()
{
  Board::initialize();

  Usart1::connect<Uart1_tx::Tx, Uart1_rx::Rx>();
  Usart1::initialize<Board::SystemClock, 115200_Bd>();

  auto hex_encode = [](const auto& begin, const auto& end) -> std::string {
    static constexpr std::array digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

    std::string str;
    str.resize(static_cast<std::size_t>((end - begin) * 2U));
    auto i = 0U;
    for (auto iter = begin; iter != end; iter++) {
      str[i++] = digits[(*iter & 0xf0) >> 4];
      str[i++] = digits[*iter & 0xf];
    }
    return str;
  };

  sum(10, 20);   // use static library

  auto build = modm::build_id();
  MODM_LOG_INFO << hex_encode(build.begin(), build.end()).c_str() << "\n\r";

  Led::set();

  while (true) {
    Led::toggle();
    modm::delay(Button::read() ? 100ms : 500ms);
  }

  return 0;
}
