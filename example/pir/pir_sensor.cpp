#include "pir_sensor.h"

#include <iostream>

#include "common/util/utils.h"

namespace example
{
namespace pir
{

void sensor(uint8_t led_pin, uint8_t sensor_pin, common::gpio::GPIO_manager &gpio_manager)
{
  gpio_manager.write(led_pin, false);
  gpio_manager.read(sensor_pin);

  bool current_state = false;
  bool previous_state = false;

  std::cout << "Waiting for PIR to settle ... " << std::endl;

  while (1 == gpio_manager.read(sensor_pin))
  {
    current_state = false;
  }

  std::cout << "  Ready" << std::endl;

  // Loop until users quits with CTRL-C
  while (true)
  {
    current_state = (0 != gpio_manager.read(sensor_pin));

    if (current_state && !previous_state)
    {
      std::cout << "  Motion detected!" << std::endl;
      gpio_manager.write(led_pin, true);

      previous_state = true;

    }
    else if (!current_state && previous_state)
    {
      std::cout << "  Ready" << std::endl;
      gpio_manager.write(led_pin, false);

      previous_state = false;
    }

    common::util::sleep_microseconds(10000);
  }
}

}
}
