// Advent of Code 2020

#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#include "../helper-classes/list-reader.h"

constexpr int row_length = 31;

namespace data {
const std::vector<std::bitset<row_length>> ParseForestMatrix(const std::vector<std::string> data) {
    std::vector<std::bitset<row_length>> ret;
    for (std::string line : data) {
        std::bitset<row_length> bit_vector(line, 0, row_length, '.', '#');
        ret.push_back(bit_vector);
    }

    return ret;
}

void PrintForestMatrix(const std::vector<std::bitset<row_length>>& matrix) {
    for (auto row : matrix) {
        std::cout << row.to_string('.', '#') << std::endl;
    }
}

} // namespace data

int main(int argc, char** argv) {
    data::ListReaderImpl list_reader("C:/Users/grhousto/advent-of-code/day-03/advent-day-03-data.txt");
    auto tree_matrix = data::ParseForestMatrix(list_reader.GetData());
    data::PrintForestMatrix(tree_matrix);
}
