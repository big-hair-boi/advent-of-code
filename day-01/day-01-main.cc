// Advent of Code 2020

#include <iostream>
#include <string>

#include "../helper-classes/int-list-reader.h"

int main(int argc, char** argv) {
    data::IntListReader list_reader("C:/Users/grhousto/advent-of-code/day-01/advent-day-01-data.csv");

    for (int line : list_reader.GetData()) {
        std::cout << line;
    }

    return 0;
}
