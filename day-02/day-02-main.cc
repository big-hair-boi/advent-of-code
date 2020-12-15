// Advent of Code 2020

#include <iostream>

#include "../helper-classes/list-reader.h"
#include "password-entry.h"

int main(int argc, char** argv) {
    data::ListReaderImpl list_reader("C:/Users/grhousto/advent-of-code/day-02/advent-day-02-data.txt");

    int num_valid_passwords = 0;
    for (std::string line : list_reader.GetData()) {
        PasswordEntry entry(line);
        if (entry.IsValid())
            ++num_valid_passwords;
    }
    std::cout << "Num Valid Passwords: " << std::to_string(num_valid_passwords)
        << "\n";
}
