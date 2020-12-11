// Advent of Code 2020

#include <iostream>

#include "../helper-classes/list-reader.h"

int main(int argc, char** argv) {
    data::ListReaderImpl list_reader("C:/Users/grhousto/advent-of-code/day-01/advent-day-01-data.csv");

    for (std::string line : list_reader.GetData()) {
        std::cout << line + "\n";
    }

    return 0;
}
