#include "utils.h"

#include <thread>
#include <chrono>

namespace common
{
namespace util
{

void sleep_seconds(uint32_t seconds)
{
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

}
}
