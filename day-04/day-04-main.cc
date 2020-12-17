// Advent of Code 2020

#include <iostream>
#include <string>
#include <unordered_map>

#include "../helper-classes/list-reader.h"
#include "../helper-classes/string-manipulation.h"

constexpr char filepath[] =
    "C:/Users/grhousto/advent-of-code/day-04/advent-day-04-data.txt";
constexpr int max_key_count = 8;

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

bool IsCredentialValidPart1(Credential credential) {
  static constexpr char optional_key[] = "cid";
  int num_keys = credential.size();
  return num_keys == max_key_count ||
         (num_keys == max_key_count - 1 &&
          credential.find(optional_key) == credential.end());
}

} // namespace

int main(int argc, char **argv) {
  std::vector<Credential> credential_list = BuildCredentialList();

  int count = 0;
  for (Credential credential : credential_list) {
    if (IsCredentialValidPart1(credential)) {
      ++count;
    }
  }
  std::cout << "Part 1 Num of Valid Credentials: " << std::to_string(count)
            << std::endl;

  return 0;
}
