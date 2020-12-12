// Advent of Code 2020

#include "int-list-reader.h"

namespace data {

std::vector<int> IntListReader::GetData() {
    std::vector<int> ret;
    std::vector<std::string> string_list = ListReader::GetStringListData();
    
    for (std::string str : string_list) {
        ret.push_back(std::stoi(str));
    }
    return ret;
}

} // namespace data
