// Advent of Code 2020

#include <iostream>

#include "../helper-classes/list-reader.h"

int main(int argc, char** argv) {
    std::cout << "this is a test";
    data::ListReaderImpl list_reader("advent-day-01-data.csv");

    for (std::string line : list_reader.GetData()) {
        std::cout << line;
    }

    return 0;
}
