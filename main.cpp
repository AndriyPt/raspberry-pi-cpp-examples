#include "gpiomanager.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void simpleLedBlinking(GpioManager &gpioManager) {

	gpioManager.write(21, true);

	sleep(2);

	gpioManager.write(21, false);

	sleep(1);

	gpioManager.write(21, true);

	sleep(2);

	gpioManager.write(21, false);

}

void runStepperMotor(GpioManager &gpioManager) {

	int timeout = 500000;

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

void irDetector(GpioManager &gpioManager) {

	const uint8_t LED_PIN = 21;
	const uint8_t SENSOR_PIN = 20;

	gpioManager.write(LED_PIN, false);
	gpioManager.read(SENSOR_PIN);

	bool current_state  = false;
	bool previous_state = false;

	printf("Waiting for PIR to settle ... \n");

	// Loop until PIR output is 0
	while (1 == gpioManager.read(SENSOR_PIN)) {
		current_state = false;

	}

	printf("  Ready \n");

	// Loop until users quits with CTRL-C
	while (true) {

		current_state = (0 != gpioManager.read(SENSOR_PIN));

	    if (current_state && !previous_state) {

	    	// PIR is triggered
	      printf("  Motion detected! \n");
	      gpioManager.write(LED_PIN, true);

	      // Record previous state
	      previous_state = true;

	    }
	    else if (!current_state && previous_state) {

	    	// PIR has returned to ready state
	    	printf("  Ready \n");
	    	gpioManager.write(LED_PIN, false);

	    	previous_state = false;
	    }

    	// Wait for 10 milliseconds
    	usleep(10000);
	}
}


int main(int argc, char **argv) {

	GpioManager gpioManager;

//	simpleLedBlinking(gpioManager);

//	runStepperMotor(gpioManager);

	irDetector(gpioManager);

	return 0;
}
