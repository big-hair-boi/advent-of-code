// Advent of Code 2020

#include <fstream>
#include <iostream>
#include <string>

#include "list-reader.h"

namespace data {

std::vector<std::string> GetStringList(const std::string& filename) {
    std::vector<std::string> data_list;

    std::ifstream file(filename);
    if (!file) {
        return data_list;
    }

    std::string str;
    while (std::getline(file, str)) {
      data_list.push_back(str);
    }
    file.close();

    return data_list;
}

std::vector<long long int> GetIntList(const std::string& filename) {
  std::vector<long long int> ret;
  std::vector<std::string> string_list = GetStringList(filename);

  for (std::string str : string_list) {
    ret.push_back(std::stoll(str));
  }
  return ret;
}

} // namespace data