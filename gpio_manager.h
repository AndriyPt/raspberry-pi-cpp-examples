#ifndef GPIOMANAGER_H_
#define GPIOMANAGER_H_

#include <stdint.h>

class GpioManager {

private:
	const int BLOCK_SIZE;

	volatile unsigned *gpio;

public:
	GpioManager();

	void setReadMode(uint8_t gpioNumber);

	bool read(uint8_t gpioNumber);
	void write(uint8_t gpioNumber, bool value);

	virtual ~GpioManager();
};

#endif /* GPIOMANAGER_H_ */
