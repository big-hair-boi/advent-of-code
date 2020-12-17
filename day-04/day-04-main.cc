// Advent of Code 2020

#include <iostream>
#include <string>
#include <unordered_map>

#include "../helper-classes/list-reader.h"
#include "../helper-classes/string-manipulation.h"

constexpr char filepath[] =
    "C:/Users/grhousto/advent-of-code/day-04/advent-day-04-data.txt";

using Credential = std::unordered_map<std::string, std::string>;

namespace {

Credential CreateCredentialObject(std::vector<std::string> str_list) {
  Credential ret;
  for (std::string str : str_list) {
    for (std::string entry : data::string_split(str, ' ')) {
      const auto entry_components = data::string_split(entry, ':');
      std::cout << "";
      ret.insert(std::pair(entry_components.at(0), entry_components.at(1)));
    }
  }
  return ret;
}

std::vector<Credential> BuildCredentialList() {
  std::vector<Credential> ret;

  std::vector<std::string> str_list;
  for (std::string line : data::GetStringList(filepath)) {
    if (line != "\n" && line.size() > 1) {
      str_list.push_back(line);
    } else {
      ret.push_back(CreateCredentialObject(str_list));
      str_list.clear();
    }
  }

  // Handle case of final entry being read in but not converted to an object
  if (str_list.size() != 0) {
    ret.push_back(CreateCredentialObject(str_list));
  }

  return ret;
}

} // namespace

int main(int argc, char **argv) {
  std::vector<Credential> credential_list = BuildCredentialList();

  // Test print credentials being successfully converted to objects
  for (const auto credential : credential_list) {
    for (const auto pair : credential) {
      std::cout << pair.first << ":" << pair.second << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}
