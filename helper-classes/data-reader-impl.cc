// Advent of Code 2020

#include <fstream>
#include <iostream>

#include "data-reader.h"

std::vector<std::string> DataReaderImpl::GetData() {
    std::vector<std::string> data_list;

    std::ifstream file(this->_filename);
    std::string str;
    while (std::getline(file, str)) {
        data_list.push_back(str);
    }

    return data_list;
}