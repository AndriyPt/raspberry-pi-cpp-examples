#include "gpiomanager.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

GpioManager::GpioManager() : BLOCK_SIZE (4 * 1024) {

	const long BCM2708_PERI_BASE = 0x20000000;
	const long GPIO_BASE = BCM2708_PERI_BASE + 0x200000;

	int mem_fd = open("/dev/mem", O_RDWR | O_SYNC);

	if (mem_fd < 0) {
		printf("can't open /dev/mem \n");
		exit(-1);
	}

	void *gpio_map = mmap(
			NULL, //Any adddress in our space will do
			BLOCK_SIZE, //Map length
			PROT_READ | PROT_WRITE, // Enable reading & writting to mapped memory
			MAP_SHARED, //Shared with other processes
			mem_fd, //File to map
			GPIO_BASE //Offset to GPIO peripheral
			);

	close(mem_fd); //No need to keep mem_fd open after mmap

	if (MAP_FAILED == gpio_map) {
		printf("mmap error %d\n", (int) gpio_map);
		exit(-1);
	}

	// Always use volatile pointer!
	gpio = (volatile unsigned *) gpio_map;
}

GpioManager::~GpioManager() {
	munmap((void*)gpio, BLOCK_SIZE);
}

void GpioManager::setReadMode(uint8_t gpioNumber) {
	*(gpio + (gpioNumber / 10)) &= ~(7 << ((gpioNumber % 10) * 3));
}


bool GpioManager::read(uint8_t gpioNumber) {

	setReadMode(gpioNumber);

	return (*(gpio + 13) & (1 << gpioNumber));
}

void GpioManager::write(uint8_t gpioNumber, bool value) {

	setReadMode(gpioNumber);

	*(gpio + (gpioNumber / 10)) |=  (1 << ((gpioNumber % 10) * 3));

	if (value) {
		*(gpio + 7) = (1 << gpioNumber);
	}
	else {
		*(gpio + 10) =  (1 << gpioNumber);
	}
}

// GPIO setup macros. Always use INP_GPIO(x) before using OUT_GPIO(x) or SET_GPIO_ALT(x,y)
//#define INP_GPIO(g) *(gpio+((g)/10)) &= ~(7<<(((g)%10)*3))
//#define OUT_GPIO(g) *(gpio+((g)/10)) |=  (1<<(((g)%10)*3))
//#define SET_GPIO_ALT(g,a) *(gpio+(((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))
//
//#define GPIO_SET *(gpio+7)  // sets   bits which are 1 ignores bits which are 0
//#define GPIO_CLR *(gpio+10) // clears bits which are 1 ignores bits which are 0
//
//#define GET_GPIO(g) (*(gpio+13)&(1<<g)) // 0 if LOW, (1<<g) if HIGH
//
//#define GPIO_PULL *(gpio+37) // Pull up/pull down
//#define GPIO_PULLCLK0 *(gpio+38) // Pull up/pull down clock
