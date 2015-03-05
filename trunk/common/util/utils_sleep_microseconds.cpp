#include "utils.h"

#include <thread>
#include <chrono>

namespace common
{
namespace util
{

void sleep_microseconds(uint32_t microseconds)
{
  std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
}

}
}
