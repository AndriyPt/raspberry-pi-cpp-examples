#ifndef GPIO_MANAGER_H_
#define GPIO_MANAGER_H_

#include <stdint.h>

namespace common
{
namespace gpio
{

class GPIO_manager
{

public:
  GPIO_manager();

  void set_read_mode(uint8_t pin);

  bool read(uint8_t pin);
  void write(uint8_t pin, bool value);

  virtual ~GPIO_manager();

private:
  const int block_size;

  volatile unsigned* gpio;
};

}
}

#endif /* GPIO_MANAGER_H_ */
