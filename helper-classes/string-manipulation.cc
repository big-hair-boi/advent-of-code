// Advent of Code
#include "string-manipulation.h"

#include <cstring>
#include <iostream>
#include <sstream>
#include <regex>

namespace data {

std::vector<std::string> string_split(const std::string &str,
                                      const std::string& delim = "\n") {
  std::vector<std::string> ret;
  std::string regex_expr = "(" + delim + ")";
  std::regex re(regex_expr);
  //the '-1' is what makes the regex split (-1 := what was not matched)
  std::sregex_token_iterator first{str.begin(), str.end(), re, -1}, last;

  std::vector<std::string> tokens{first, last};
  for (auto t : tokens) {
      std::cout << t << std::endl;
      ret.push_back(t);
  }
  return ret;
}

} // namespace data
