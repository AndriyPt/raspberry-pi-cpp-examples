#include "stepper_motor.h"

#include "common/util/utils.h"

namespace example
{
namespace motor
{

void stepper(std::array<uint8_t, 4> pins, common::gpio::GPIO_manager &gpio_manager)
{
  int timeout = 50000;

  gpio_manager.write(pins[0], false);
  gpio_manager.write(pins[1], false);
  gpio_manager.write(pins[2], false);
  gpio_manager.write(pins[3], false);

  for (int i = 0; i < 20; i++)
  {
    gpio_manager.write(pins[2], false);
    common::util::sleep_microseconds(timeout);

    gpio_manager.write(pins[0], true);
    common::util::sleep_microseconds(timeout);

    gpio_manager.write(pins[3], false);
    common::util::sleep_microseconds(timeout);

    gpio_manager.write(pins[1], true);
    common::util::sleep_microseconds(timeout);

    gpio_manager.write(pins[0], false);
    common::util::sleep_microseconds(timeout);

    gpio_manager.write(pins[2], true);
    common::util::sleep_microseconds(timeout);

    gpio_manager.write(pins[1], false);
    common::util::sleep_microseconds(timeout);

    gpio_manager.write(pins[3], true);
    common::util::sleep_microseconds(timeout);
  }
}

}
}
