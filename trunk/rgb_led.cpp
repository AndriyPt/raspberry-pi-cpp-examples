#include "rgb_led.h"

#include <unistd.h>

void rgbLed(GpioManager &gpioManager) {

	const int RED_PORT = 12;
	const int GREEN_PORT = 16;
	const int BLUE_PORT = 20;

	gpioManager.write(RED_PORT, false);
	gpioManager.write(GREEN_PORT, false);
	gpioManager.write(BLUE_PORT, false);

	for (int i = 0; i < 3; i++) {

		gpioManager.write(RED_PORT, true);

		sleep(2);

		gpioManager.write(RED_PORT, false);
		gpioManager.write(GREEN_PORT, true);

		sleep(2);

		gpioManager.write(GREEN_PORT, false);
		gpioManager.write(BLUE_PORT, true);

		sleep(2);

		gpioManager.write(RED_PORT, true);
		gpioManager.write(GREEN_PORT, true);
		gpioManager.write(BLUE_PORT, false);

		sleep(2);

		gpioManager.write(RED_PORT, false);
		gpioManager.write(GREEN_PORT, true);
		gpioManager.write(BLUE_PORT, true);

		sleep(2);

		gpioManager.write(RED_PORT, true);
		gpioManager.write(GREEN_PORT, false);
		gpioManager.write(BLUE_PORT, true);

		sleep(2);

		gpioManager.write(RED_PORT, true);
		gpioManager.write(GREEN_PORT, true);
		gpioManager.write(BLUE_PORT, true);

		sleep(2);

		gpioManager.write(RED_PORT, false);
		gpioManager.write(GREEN_PORT, false);
		gpioManager.write(BLUE_PORT, false);
	}
}

