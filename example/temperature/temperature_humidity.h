#ifndef TEMPERATURE_HUMIDITY_H_
#define TEMPERATURE_HUMIDITY_H_

#include "common/gpio/gpio_manager.h"

namespace example
{
namespace temperature
{

void temperature_humidity_sensor(uint8_t pin, common::gpio::GPIO_manager &gpio_manager);

}
}

#endif /* TEMPERATURE_HUMIDITY_H_ */
