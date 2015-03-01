#ifndef MAX_PRIORITY_H_
#define MAX_PRIORITY_H_

namespace common
{
namespace util
{

class Max_priority
{
public:
    Max_priority();
    void set_default_priority();
    ~Max_priority();

private:
    void set_max_priority();

    bool default_priority;
};

}
}

#endif /* MAX_PRIORITY_H_ */
