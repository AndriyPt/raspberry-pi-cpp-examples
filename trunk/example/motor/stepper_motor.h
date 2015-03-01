#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include <array>

#include "common/gpio/gpio_manager.h"

namespace example
{
namespace motor
{

void stepper(std::array<uint8_t, 4> pins, common::gpio::GPIO_manager &gpio_manager);

}
}

#endif /* STEPPER_MOTOR_H_ */
