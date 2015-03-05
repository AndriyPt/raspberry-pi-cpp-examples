#ifndef APPLICATION_ERROR_H_
#define APPLICATION_ERROR_H_

#include <exception>
#include <string>
#include <sstream>

#include "common/util/utils.h"

namespace common
{
namespace error
{

class Application_error : public std::exception
{
public:

  virtual ~Application_error() throw ()
  {
  }

  std::string get_message()
  {
    return this->message;
  }

  template<typename ... Arguments>
    static void raise(Arguments ... arguments)
    {
      throw Application_error(common::util::concat(arguments...));
    }

private:

  Application_error(std::string value)
  {
    this->message = value;
  }

  std::string message;
};

}
}

#endif /* APPLICATION_ERROR_H_ */
