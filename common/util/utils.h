#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <sstream>

namespace common
{
namespace util
{

template<typename T>
  T parse_string(std::string value)
  {

    std::stringstream string_stream;

    string_stream << value;

    T result;

    string_stream >> result;

    return result;
  }

template<typename T>
  std::string concat(T value)
  {
    std::stringstream string_stream;
    string_stream << value;
    return string_stream.str();
  }

template<typename T, typename ... Args>
  std::string concat(T first, Args ... args)
  {
    std::stringstream string_stream;
    string_stream << first << concat(args...);
    return string_stream.str();
  }

void sleep_seconds(uint32_t seconds);

void sleep_microseconds(uint32_t microseconds);

void short_delay();

}
}

#endif /* UTILS_H_ */
