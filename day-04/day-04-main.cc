// Advent of Code 2020
#include <array>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "../helper-classes/list-reader.h"
#include "../helper-classes/string-manipulation.h"

constexpr char filepath[] =
    "../day-04/advent-day-04-data.txt";
constexpr int max_key_count = 8;

using Credential = std::unordered_map<std::string, std::string>;
using Pair = std::pair<std::string, std::string>;

namespace {

Credential CreateCredentialObject(std::vector<std::string> str_list) {
  Credential ret;
  for (const std::string& str : str_list) {
    for (std::string entry : data::string_split(str, " ")) {
      const auto entry_components = data::string_split(entry, ":");
      ret.insert(std::pair(entry_components.at(0), entry_components.at(1)));
    }
  }
  return ret;
}

std::vector<Credential> BuildCredentialList() {
  std::vector<Credential> ret;
  std::vector<std::string> str_list;
  for (const std::string& line : data::GetStringList(filepath)) {
    // This line is a demarcation between credentials.
    if (std::all_of(line.begin(), line.end(),isspace)) {
      ret.push_back(CreateCredentialObject(str_list));
      str_list.clear();
    } else {
      str_list.push_back(line);
    }
  }

  // Handle case of final entry being read in but not converted to an object
  if (!str_list.empty()) {
    ret.push_back(CreateCredentialObject(str_list));
  }

  return ret;
}

std::ostream& operator<<(std::ostream& os, const Credential& c)
{
  for (const auto pair : c) {
    os << pair.first << ":" << pair.second << std::endl;
  }
  return os;
}

bool IsCredentialValidPart1(const Credential credential) {
  static constexpr char optional_key[] = "cid";
  const int num_keys = credential.size();
  return num_keys == max_key_count ||
         (num_keys == max_key_count - 1 &&
          credential.find(optional_key) == credential.end());
}

bool IsValidYear(const Pair &pair) {
  std::string::size_type len = 0;
  const int value = std::stoi(pair.second, &len);
  if (len != 4) {
    return false;
  }
  const std::string& key = pair.first;
  return (key == "byr" && value >= 1920 && value <= 2002) ||
         (key == "iyr" && value >= 2010 && value <= 2020) ||
         (key == "eyr" && value >= 2020 && value <= 2030);
}

bool IsValidHeight(const Pair &pair) {
  const std::string& str_value = pair.second;
  const int str_size = str_value.size();
  if (str_size < 4)
    return false;

  if (!std::regex_match(str_value, std::regex("[0-9]{2,3}(in|cm)")))
    return false;

  const std::string value_substr = str_value.substr(0, str_size - 2);
  if (value_substr.find_first_not_of("0123456789") != std::string::npos)
    return false;
  const int height_value = std::stoi(value_substr);

  const std::string unit = pair.second.substr(str_size - 2, str_size);
  if (unit == "cm")
    return height_value >= 150 && height_value <= 193;
  else if (unit == "in")
    return height_value >= 59 && height_value <= 76;
  else
    return false;
}

bool IsValidHairColor(const Pair &pair) {
  const std::string& str_value = pair.second;
  if (str_value.size() != 7)
    return false;

  return std::regex_match(str_value, std::regex("#[0-9a-f]{6}"));
}

bool IsValidEyeColor(const Pair &pair) {
  static const std::unordered_set<std::string> valid_colors = {
      "amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

  const std::string& value = pair.second;
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
  static constexpr std::array<const char*, 3> year_fields {{"eyr", "iyr", "byr"}};
  for (auto* year : year_fields) {
    const auto pair = credential.find(year);
    if (pair == credential.end() || !IsValidYear(*pair)) {
      return false;
    }
  }

  const auto hgt_pair = credential.find("hgt");
  if (hgt_pair == credential.end() || !IsValidHeight(*hgt_pair)) {
    return false;
  }

  const auto hcl_pair = credential.find("hcl");
  if (hcl_pair == credential.end() || !IsValidHairColor(*hcl_pair)) {
    return false;
  }

  const auto ecl_pair = credential.find("ecl");
  if (ecl_pair == credential.end() || !IsValidEyeColor(*ecl_pair)) {
    return false;
  }

  const auto pid_pair = credential.find("pid");
  if (pid_pair == credential.end() || !IsValidPid(*pid_pair)) {
    return false;
  }

  if (credential.size() == 7) {
    return true;
  }
  return (credential.size() == 8 && credential.find("cid") != credential.end());
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
  for (const auto& credential : credential_list) {
    if (IsCredentialValidPart2(credential)) {
      ++count2;
    }
  }
  std::cout << "Part 2 Num of Valid Credentials: " << std::to_string(count2)
            << std::endl;

  return 0;
}
