// Advent of Code 2020

#include <iostream>

#include "password-entry.h"

// To reviewers: while this may not use std functions, this should be minimal
// iterations over the string (2 passes to be exact).
PasswordEntry::PasswordEntry(const std::string line_entry) {
    // Heuristic assumption: there are no numbers larger than 2 digits
    int lindex = 0;
    int rindex = 1;
    if (line_entry[rindex] != '-') {
        ++rindex;
    }
    _low_value = std::stoi(line_entry.substr(lindex, rindex));
    lindex = ++rindex;

    // Same heuristic assumption as before: no more than 2 digit numbers
    if (line_entry[++rindex] != ' ') {
        ++rindex;
    }
    _high_value = std::stoi(line_entry.substr(lindex, rindex));

    // Heuristic assumption: there is only a single character to check for
    lindex = ++rindex;
    _required_letter = line_entry[rindex++];

    // Heuristic assumption: there is always ": " after every required letter
    lindex += 3;
    _password = line_entry.substr(lindex, line_entry.length());
}

bool PasswordEntry::IsValid() {
    /*
    // Original validation method
    int count = 0;
    for (char c : _password) {
        if (c == _required_letter) {
            ++count;
        }
    }
    return count >= _low_value && count <= _high_value;
    */

   // Second validation method
    return (_password[_low_value - 1] == _required_letter)
        != (_password[_high_value - 1] == _required_letter);
}