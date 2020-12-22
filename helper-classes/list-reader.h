// Advent of Code 2020

#ifndef HELPER_CLASSES_LIST_READER_H_
#define HELPER_CLASSES_LIST_READER_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace data {

// Read in data from file and return as a line-by-line list.
std::vector<std::string> GetStringList(const std::string& filename);
std::vector<int> GetIntList(const std::string& filename);

} // namespace data

#endif // HELPER_CLASSES_LIST_READER_H_
