#include "led.h"

#include "common/util/utils.h"

namespace example
{
namespace led
{

void rgb(uint8_t red_pin, uint8_t green_pin, uint8_t blue_pin,
		common::gpio::GPIO_manager &gpio_manager)
{

	gpio_manager.write(red_pin, false);
	gpio_manager.write(green_pin, false);
	gpio_manager.write(blue_pin, false);

	for (int i = 0; i < 3; i++)
	{
		gpio_manager.write(red_pin, true);

		common::util::sleep_seconds(2);

		gpio_manager.write(red_pin, false);
		gpio_manager.write(green_pin, true);

		common::util::sleep_seconds(2);

		gpio_manager.write(green_pin, false);
		gpio_manager.write(blue_pin, true);

		common::util::sleep_seconds(2);

		gpio_manager.write(red_pin, true);
		gpio_manager.write(green_pin, true);
		gpio_manager.write(blue_pin, false);

		common::util::sleep_seconds(2);

		gpio_manager.write(red_pin, false);
		gpio_manager.write(green_pin, true);
		gpio_manager.write(blue_pin, true);

		common::util::sleep_seconds(2);

		gpio_manager.write(red_pin, true);
		gpio_manager.write(green_pin, false);
		gpio_manager.write(blue_pin, true);

		common::util::sleep_seconds(2);

		gpio_manager.write(red_pin, true);
		gpio_manager.write(green_pin, true);
		gpio_manager.write(blue_pin, true);

		common::util::sleep_seconds(2);

		gpio_manager.write(red_pin, false);
		gpio_manager.write(green_pin, false);
		gpio_manager.write(blue_pin, false);
	}
}

}
}
