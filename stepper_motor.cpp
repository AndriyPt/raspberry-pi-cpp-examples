#include "stepper_motor.h"

#include <unistd.h>

void stepperMotor(GpioManager &gpioManager) {

	int timeout = 50000;

	int ports[] = { 12, 16, 20, 21 };

	gpioManager.write(ports[0], false);
	gpioManager.write(ports[1], false);
	gpioManager.write(ports[2], false);
	gpioManager.write(ports[3], false);

	for (int i = 0; i < 20; i++) {
		gpioManager.write(ports[2], false);
		usleep(timeout);

		gpioManager.write(ports[0], true);
		usleep(timeout);

		gpioManager.write(ports[3], false);
		usleep(timeout);

		gpioManager.write(ports[1], true);
		usleep(timeout);

		gpioManager.write(ports[0], false);
		usleep(timeout);

		gpioManager.write(ports[2], true);
		usleep(timeout);

		gpioManager.write(ports[1], false);
		usleep(timeout);

		gpioManager.write(ports[3], true);
		usleep(timeout);
	}
}
