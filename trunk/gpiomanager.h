#ifndef GPIOMANAGER_H_
#define GPIOMANAGER_H_

#include <stdint.h>

class GpioManager {

private:
	const int BLOCK_SIZE;

	volatile unsigned *gpio;

public:
	GpioManager();

	uint8_t read(uint8_t gpioNumber);
	void write(uint8_t gpioNumber, bool value);

	virtual ~GpioManager();
};

#endif /* GPIOMANAGER_H_ */
