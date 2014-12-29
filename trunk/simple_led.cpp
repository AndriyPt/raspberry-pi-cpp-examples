#include "simple_led.h"

#include <unistd.h>

void simpleLed(GpioManager &gpioManager) {

	gpioManager.write(21, true);

	sleep(2);

	gpioManager.write(21, false);

	sleep(1);

	gpioManager.write(21, true);

	sleep(2);

	gpioManager.write(21, false);

}


