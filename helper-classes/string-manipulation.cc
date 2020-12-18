// Advent of Code
#include "string-manipulation.h"

#include <cstring>
#include <iostream>
#include <sstream>

namespace data {

std::vector<std::string> string_split(const std::string &str,
                                      char delim = '\n') {
  std::vector<std::string> ret;
  std::stringstream ss(str);
  while(ss.good()) {
      std::string substr;
      std::getline(ss, substr, delim);
      ret.push_back(substr);
  }
  return ret;
}

} // namespace data
