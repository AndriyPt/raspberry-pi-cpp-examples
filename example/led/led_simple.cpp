#include "led.h"

#include "common/util/utils.h"

namespace example
{
namespace led
{

void simple(uint8_t pin, common::gpio::GPIO_manager &gpio_manager)
{

    gpio_manager.write(pin, true);

	common::util::sleep_seconds(2);

	gpio_manager.write(pin, false);

	common::util::sleep_seconds(2);

	gpio_manager.write(pin, true);

	common::util::sleep_seconds(2);

	gpio_manager.write(pin, false);

}

}
}


