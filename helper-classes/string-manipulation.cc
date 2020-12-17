// Advent of Code

#include <cstring>

#include "string-manipulation.h"

namespace data {

std::vector<std::string> string_split(const std::string &str,
                                                     char delim = '\n') {
  std::vector<std::string> ret;

  char *str_mutable = const_cast<char *>(str.c_str());
  for (char *token = std::strtok(str_mutable, &delim); token != nullptr;
       token = std::strtok(nullptr, &delim)) {
      ret.push_back(std::string(token));
  }

  return ret;
}

} // namespace data
