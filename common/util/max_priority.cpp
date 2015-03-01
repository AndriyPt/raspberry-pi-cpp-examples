#include "max_priority.h"

#include <sched.h>
#include <string.h>

namespace common
{
namespace util
{

Max_priority::Max_priority()
{
    this->set_max_priority();
}

Max_priority::~Max_priority()
{
    this->set_default_priority();
}

void Max_priority::set_default_priority()
{
    if (!this->default_priority)
    {
        struct sched_param scheduler;
        memset(&scheduler, 0, sizeof(scheduler));
        scheduler.sched_priority = 0;
        sched_setscheduler(0, SCHED_OTHER, &scheduler);

        this->default_priority = true;
    }
}

void Max_priority::set_max_priority()
{
    struct sched_param scheduler;
    memset(&scheduler, 0, sizeof(scheduler));
    scheduler.sched_priority = sched_get_priority_max(SCHED_FIFO);
    sched_setscheduler(0, SCHED_FIFO, &scheduler);

    this->default_priority = false;
}

}
}
