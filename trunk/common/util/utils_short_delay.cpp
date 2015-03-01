#include "utils.h"

namespace common
{
namespace util
{

void short_delay()
{
    for (volatile uint8_t i = 0; 63 != i; ++i)
    {
    }
}

}
}

