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

    //std::cout << "Low Range: " << std::to_string(_low_range) << "\n";

    // Same heuristic assumption as before: no more than 2 digit numbers
    if (line_entry[++rindex] != ' ') {
        ++rindex;
    }
    _high_range = std::stoi(line_entry.substr(lindex, rindex));

    // std::cout << "High Range: " << std::to_string(_high_range) << "\n";

    // Heuristic assumption: there is only a single character to check for
    lindex = ++rindex;
    _required_letter = line_entry[rindex++];

    // std::cout << "Required letter: " << _required_letter << "\n";

    // Heuristic assumption: there is always ": " after every required letter
    lindex += 3;
    _password = line_entry.substr(lindex, line_entry.length());

    //std::cout << "Password: '" << _password << "'\n";
}