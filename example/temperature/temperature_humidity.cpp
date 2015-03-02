#include "temperature_humidity.h"

#include <iostream>

#include "common/util/utils.h"
#include "common/util/max_priority.h"
#include "common/error/application_error.h"

namespace example
{
namespace temperature
{

void temperature_humidity_sensor(uint8_t pin, common::gpio::GPIO_manager &gpio_manager)
{
    const uint32_t max_iterations = 32000;

    const uint8_t data_count = 1 + 41 * 2;
    uint32_t data_counts[data_count] = { 0 };

    common::util::Max_priority max_priority;

    gpio_manager.write(pin, true);
    common::util::sleep_microseconds(500000);

    gpio_manager.write(pin, false);
    common::util::sleep_microseconds(18000);

    gpio_manager.write(pin, true);
    gpio_manager.set_read_mode(pin);

    common::util::short_delay();

    bool previousValue = true;

    for (int i = 0; data_count != i; ++i)
    {
        while (previousValue == gpio_manager.read(pin))
        {
            if (max_iterations == ++data_counts[i])
            {
                common::error::Application_error::raise("Timeout waiting for DHT response");
            }
        }
        previousValue = !previousValue;
    }

    max_priority.set_default_priority();

    uint32_t threshold = 0;
    for (int i = 3; data_count != i; i += 2)
    {
        threshold += data_counts[i];
    }
    threshold /= data_count - 3;

    uint8_t data[5] = { 0 };
    for (int i = 4; i < data_count; i += 2)
    {
        int index = (i - 4) >> 4;
        data[index] <<= 1;
        if (data_counts[i] >= threshold)
        {
            data[index] |= 1;
        }
    }

    if (data[4] != ((data[0] + data[1] + data[2] + data[3]) & 0xFF))
    {
        common::error::Application_error::raise("Checksum of received data failed");
    }

    std::cout << "Temperature "<< (int) data[2] << "." << (int) data[3]
              << "C, humidity " << (int) data[0] << "." << (int) data[1] << "%" << std::endl;
}

}
}
