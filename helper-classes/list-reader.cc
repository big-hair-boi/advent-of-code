// Advent of Code 2020

#include <fstream>
#include <iostream>
#include <string>

#include "list-reader.h"

namespace data {

template <typename data_type>
std::vector<std::string> ListReader<data_type>::GetStringListData() {
  std::vector<std::string> data_list;

  std::ifstream file(this->_filename);
  if (!file)
    std::cout << "File couldn't be opened\n";

  std::string str;
  while (std::getline(file, str)) {
    data_list.push_back(str);
  }
  file.close();

  return data_list;
}

} // namespace data