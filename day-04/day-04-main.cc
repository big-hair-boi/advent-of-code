// Advent of Code 2020

#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "../helper-classes/list-reader.h"
#include "../helper-classes/string-manipulation.h"

constexpr char filepath[] =
    "C:/Users/grhousto/advent-of-code/day-04/advent-day-04-data.txt";
constexpr int max_key_count = 8;

using Credential = std::unordered_map<std::string, std::string>;
using Pair = std::pair<std::string, std::string>;

namespace {

Credential CreateCredentialObject(std::vector<std::string> str_list) {
  Credential ret;
  for (std::string str : str_list) {
    for (std::string entry : data::string_split(str, ' ')) {
      const auto entry_components = data::string_split(entry, ':');
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

void PrintCredential(const Credential &credential) {
  for (const auto pair : credential) {
    std::cout << pair.first << ":" << pair.second << std::endl;
  }
}

bool IsCredentialValidPart1(const Credential credential) {
  static constexpr char optional_key[] = "cid";
  int num_keys = credential.size();
  return num_keys == max_key_count ||
         (num_keys == max_key_count - 1 &&
          credential.find(optional_key) == credential.end());
}

bool IsValidYear(const Pair &pair) {
  if (pair.second.size() != 4)
    return false;

  if (pair.second.find_first_not_of("0123456789") != std::string::npos)
    return false;
  const int value = std::stoi(pair.second);

  const std::string key = pair.first;
  return (key == "byr" && value >= 1920 && value <= 2002) ||
         (key == "iyr" && value >= 1920 && value <= 2020) ||
         (key == "eyr" && value >= 2020 && value <= 2030);
}

bool IsValidHeight(const Pair &pair) {
  const std::string str_value = pair.second;
  const int str_size = str_value.size();
  // std::cout << "Height str value: '" << str_value << "'" << std::endl <<
  // std::flush;

  if (str_size < 4)
    return false;

  if (!std::regex_match(str_value, std::regex("[0-9]{2,3}(in|cm)")))
    return false;

  const std::string value_substr = str_value.substr(0, str_size - 2);
  if (value_substr.find_first_not_of("0123456789") != std::string::npos)
    return false;
  const int height_value = std::stoi(value_substr);

  const std::string unit = pair.second.substr(str_size - 2, str_size);
  // std::cout << "unit: '" << unit << "'" << std::endl << std::flush;
  if (unit == "cm")
    return height_value >= 150 && height_value <= 193;
  else if (unit == "in")
    return height_value >= 59 && height_value <= 76;
  else
    return false;
}

bool IsValidHairColor(const Pair &pair) {
  const std::string str_value = pair.second;
  if (str_value.size() != 7)
    return false;

  return std::regex_match(str_value, std::regex("#[0-9a-f]{6}"));
}

bool IsValidEyeColor(const Pair &pair) {
  static const std::unordered_set<std::string> valid_colors = {
      "amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

  const std::string value = pair.second;
  if (value.size() != 3)
    return false;

  return valid_colors.find(value) != valid_colors.end();
}

bool IsValidPid(const Pair &pair) {
  const std::string str_value = pair.second;
  if (str_value.size() != 9)
    return false;

  return str_value.find_first_not_of("0123456789") == std::string::npos;
}

bool IsCredentialValidPart2(Credential credential) {
  // PrintCredential(credential);
  const auto byr_pair = credential.find("byr");
  if (byr_pair == credential.end() || !IsValidYear(*byr_pair)) {
    // std::cout << "failed byr; " << std::endl << std::flush;
    return false;
  }
  // std::cout << "checked byr; " << std::flush;

  const auto iyr_pair = credential.find("iyr");
  if (iyr_pair == credential.end() || !IsValidYear(*iyr_pair)) {
    // std::cout << "failed iyr; " << std::endl << std::flush;
    return false;
  }
  // std::cout << "checked iyr; " << std::flush;

  const auto eyr_pair = credential.find("eyr");
  if (eyr_pair == credential.end() || !IsValidYear(*eyr_pair)) {
    // std::cout << "failed eyr; " << std::endl << std::flush;
    return false;
  }
  // std::cout << "checked eyr; " << std::flush;

  const auto hgt_pair = credential.find("hgt");
  if (hgt_pair == credential.end() || !IsValidHeight(*hgt_pair)) {
    std::cout << "failed hgt; " << std::endl << std::flush;
    return false;
  }
  // std::cout << "checked hgt; " << std::flush;

  const auto hcl_pair = credential.find("hcl");
  if (hcl_pair == credential.end() || !IsValidHairColor(*hcl_pair)) {
    // std::cout << "failed hcl; " << std::endl << std::flush;
    return false;
  }
  // std::cout << "checked hcl; " << std::flush;

  const auto ecl_pair = credential.find("ecl");
  if (ecl_pair == credential.end() || !IsValidEyeColor(*ecl_pair)) {
    // std::cout << "failed ecl; " << std::endl << std::flush;
    return false;
  }
  // std::cout << "checked ecl; " << std::flush;

  const auto pid_pair = credential.find("pid");
  if (pid_pair == credential.end() || !IsValidPid(*pid_pair)) {
    // std::cout << "failed pid; " << std::endl << std::flush;
    return false;
  }
  // std::cout << "checked pid; " << std::flush;

  const auto cid_pair = credential.find("cid");
  return (credential.size() == 8 && cid_pair != credential.end()) ||
         credential.size() == 7;
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

  int count2 = 0;
  for (Credential credential : credential_list) {
    if (IsCredentialValidPart2(credential)) {
      PrintCredential(credential);
      ++count2;
    }
    std::cout << std::endl;
  }
  std::cout << "Part 2 Num of Valid Credentials: " << std::to_string(count2)
            << std::endl;

  return 0;
}
