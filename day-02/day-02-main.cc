// Advent of Code 2020

#include "../helper-classes/list-reader.h"
#include "password-entry.h"

int main(int argc, char** argv) {
    data::ListReaderImpl list_reader("C:/Users/grhousto/advent-of-code/day-02/advent-day-02-data.txt");

    for (std::string line : list_reader.GetData()) {
        PasswordEntry entry(line);
    }
}
