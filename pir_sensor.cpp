#include "pir_sensor.h"

#include <unistd.h>
#include <stdio.h>

void pirSensor(GpioManager &gpioManager) {

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



