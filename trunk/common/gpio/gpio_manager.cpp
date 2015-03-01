#include "gpio_manager.h"

#include <string>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#include "common/error/application_error.h"

namespace common
{
namespace gpio
{

GPIO_manager::GPIO_manager() : block_size (4 * 1024)
{
	const long bcm2708_peri_base = 0x20000000;
	const long gpio_base = bcm2708_peri_base + 0x200000;
	const std::string memory_file_name("/dev/mem");

	int mem_fd = open(memory_file_name.c_str(), O_RDWR | O_SYNC);

	if (mem_fd < 0)
	{
	    common::error::Application_error::raise("can't open ", memory_file_name);
	}

	void *gpio_map = mmap(
                NULL, //Any adddress in our space will do
                block_size, //Map length
                PROT_READ | PROT_WRITE, // Enable reading & writing to mapped memory
                MAP_SHARED, //Shared with other processes
                mem_fd, //File to map
                gpio_base //Offset to GPIO peripheral
			);

	close(mem_fd);

	if (MAP_FAILED == gpio_map)
	{
	    common::error::Application_error::raise("mmap error ", (int) gpio_map);
	}

	// Always use volatile pointer!
	gpio = (volatile unsigned *) gpio_map;
}

GPIO_manager::~GPIO_manager()
{
	munmap((void*)gpio, block_size);
}

void GPIO_manager::set_read_mode(uint8_t pin)
{
	*(gpio + (pin / 10)) &= ~(7 << ((pin % 10) * 3));
}


bool GPIO_manager::read(uint8_t pin)
{
	set_read_mode(pin);
	return (*(gpio + 13) & (1 << pin));
}

void GPIO_manager::write(uint8_t pin, bool value)
{
    set_read_mode(pin);
	*(gpio + (pin / 10)) |=  (1 << ((pin % 10) * 3));

	if (value)
	{
		*(gpio + 7) = (1 << pin);
	}
	else
	{
		*(gpio + 10) =  (1 << pin);
	}
}

}
}
