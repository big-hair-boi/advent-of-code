// Advent of Code 2020

#ifndef DAY_02_PASSWORD_ENTRY_H_
#define DAY_02_PASSWORD_ENTRY_H_

#include <string>

class PasswordEntry {
  public:
    PasswordEntry(const std::string line_entry);
    ~PasswordEntry() = default;
    PasswordEntry(const PasswordEntry&) = delete;
    const PasswordEntry& operator=(const PasswordEntry&) = delete;

  private:
    std::string _password;
    char _required_letter;
    int _low_range;
    int _high_range;
};

#endif // DAY_02_PASSWORD_ENTRY_H_
