#ifndef PIR_SENSOR_H_
#define PIR_SENSOR_H_

#include "common/gpio/gpio_manager.h"

namespace example
{
namespace pir
{

void sensor(uint8_t led_pin, uint8_t sensor_pin, common::gpio::GPIO_manager &gpio_manager);


}
}

#endif /* PIR_SENSOR_H_ */
