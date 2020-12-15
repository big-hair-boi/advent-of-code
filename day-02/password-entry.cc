// Advent of Code 2020

#include <iostream>

#include "password-entry.h"

PasswordEntry::PasswordEntry(const std::string line_entry) {
    // Heuristic assumption: there are no numbers larger than 2 digits
    int lindex = 0;
    int rindex = 1;
    if (line_entry[rindex] != '-') {
        ++rindex;
    }
    _low_range = std::stoi(line_entry.substr(lindex, rindex));
    lindex = ++rindex;

    std::cout << "Low Range: " << std::to_string(_low_range) << "\n";
}