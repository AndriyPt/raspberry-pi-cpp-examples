
#include <iostream>

#include "common/util/utils.h"
#include "common/gpio/gpio_manager.h"
#include "common/error/application_error.h"

#include "example/led/led.h"
#include "example/motor/stepper_motor.h"
#include "example/pir/pir_sensor.h"
#include "example/temperature/temperature_humidity.h"


int main(int argc, char **argv)
{
    long selection = 0;

    if (argc > 1)
    {
        selection = common::util::parse_string<long>(argv[1]);
    }
    else
    {
        std::cout << "Please select which example to run" << std::endl
                << "  1 - Simple LED Blinking" << std::endl
                << "  2 - RGB LED Blinking" << std::endl
                << "  3 - Stepper Motor" << std::endl
                << "  4 - PIR (Passive Infrared) sensor" << std::endl
                << "  5 - Temperature and humidity sensor" << std::endl;

        std::cin >> selection;
    }

    common::gpio::GPIO_manager gpio_manager;

    try
    {
        switch (selection)
        {
            case 1:
            {
                example::led::simple(21, gpio_manager);
                break;
            }

            case 2:
            {
                example::led::rgb(12, 16, 20, gpio_manager);
                break;
            }

            case 3:
            {
                example::motor::stepper({ 12, 16, 20, 21 }, gpio_manager);
                break;
            }

            case 4:
            {
                example::pir::sensor(21, 20, gpio_manager);
                break;
            }

            case 5:
            {
                example::temperature::temperature_humidity_sensor(18, gpio_manager);
                break;
            }

            default:
            {
                std::cout << "Invalid selection " << std::endl
                          << "  Please run application again." << std::endl;
                break;
            }
        }
    }
    catch (common::error::Application_error &ex)
    {
        std::cout << "Error occurred during sample execution:" << std::endl
                << ex.get_message() << std::endl;
    }

    return 0;
}
