#ifndef ERROR_H
#define ERROR_H

#include <cstring>
#include <string>
#include <sstream>


namespace openmc {


extern "C" void fatal_error_from_c(const char* message, int message_len);
extern "C" void warning_from_c(const char* message, int message_len);
extern "C" void write_message_from_c(const char* message, int message_len,
                                     int level);

inline
void fatal_error(const char *message)
{
  fatal_error_from_c(message, strlen(message));
}

inline
void fatal_error(const std::string &message)
{
  fatal_error_from_c(message.c_str(), message.length());
}

inline
void fatal_error(const std::stringstream &message)
{
  fatal_error(message.str());
}

inline
void warning(const std::string& message)
{
  warning_from_c(message.c_str(), message.length());
}

inline
void warning(const std::stringstream& message)
{
  warning(message.str());
}

inline
void write_message(const char* message, int level)
{
  write_message_from_c(message, strlen(message), level);
}

inline
void write_message(const std::string& message, int level)
{
  write_message_from_c(message.c_str(), message.length(), level);
}

inline
void write_message(const std::stringstream& message, int level)
{
  write_message(message.str(), level);
}

} // namespace openmc
#endif // ERROR_H
