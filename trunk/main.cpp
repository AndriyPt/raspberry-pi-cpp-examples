#include "gpio_manager.h"

#include "simple_led.h"
#include "rgb_led.h"
#include "stepper_motor.h"
#include "pir_sensor.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

	long selection = 0;

	if (argc > 1) {
		selection = strtol(argv[1], NULL, 10);
	}
	else {
		printf("Please select which example to run \n"
				"  1 - Simple LED Blinking \n"
				"  2 - RGB LED Blinking \n"
				"  3 - Stepper Motor \n"
				"  4 - PIR (Passive Infrared) sensor \n");

		scanf("%ld", &selection);
	}

	GpioManager gpioManager;

	switch (selection) {

		case 1: {
			simpleLed(gpioManager);
			break;
		}

		case 2: {
			rgbLed(gpioManager);
			break;
		}

		case 3: {
			stepperMotor(gpioManager);
			break;
		}

		case 4: {
			pirSensor(gpioManager);
			break;
		}

		default: {
			printf("Invalid selection \n "
				   "  Please run application again. \n");
			break;
		}
	}

	return 0;
}