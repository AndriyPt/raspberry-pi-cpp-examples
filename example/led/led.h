#ifndef LED_H_
#define LED_H_

#include "common/gpio/gpio_manager.h"

namespace example
{
namespace led
{

void simple(uint8_t pin, common::gpio::GPIO_manager &gpio_manager);

void rgb(uint8_t red_pin, uint8_t green_pin, uint8_t blue_pin, common::gpio::GPIO_manager &gpio_manager);

}
}

#endif /* LED_H_ */
