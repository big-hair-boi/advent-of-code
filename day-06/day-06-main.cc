// Advent of Code 2020

#include <array>
#include <string>
#include <vector>

#include "../helper-classes/list-reader.h"

using CustomForm = std::array<bool, 26>;

constexpr char filepath[] = "../day-06/advent-day-06-data.txt";
constexpr const CustomForm EMPTY_FORM = {false, false, false, false, false,
                                         false, false, false, false, false,
                                         false, false, false, false, false,
                                         false, false, false, false, false,
                                         false, false, false, false, false,
                                         false};

namespace {

CustomForm CreateCustomFormObject(const std::vector<std::string> &str_list) {
  CustomForm ret = EMPTY_FORM;
  for (const std::string &str : str_list) {
    for (const char &c : str) {
      ret[c - 'a'] = true;
    }
  }
  return ret;
}

std::vector<CustomForm> BuildCustomFormList() {
  std::vector<CustomForm> ret;
  std::vector<std::string> str_list;
  for (const std::string &line : data::GetStringList(filepath)) {
    // This line is a demarcation between customs forms.
    if (std::all_of(line.begin(), line.end(), isspace)) {
      ret.push_back(CreateCustomFormObject(str_list));
      str_list.clear();
    } else {
      str_list.push_back(line);
    }
  }

  // Handle case of final entry being read in but not converted to an object
  if (!str_list.empty()) {
    ret.push_back(CreateCustomFormObject(str_list));
  }

  return ret;
}

int TotalQuestionsAnswered(const CustomForm& form) {
  int count = 0;
  for (const bool& answer_yes : form) {
    if (answer_yes)
      ++count;
  }
  return count;
}

} // namespace

int main(int argc, char **argv) {
  const auto customs_list = BuildCustomFormList();
  int count = 0;
  for (const auto& cusotms_form : customs_list) {
    count += TotalQuestionsAnswered(cusotms_form);
  }
  std::cout << "Part 1 - Total yes answers: " << std::to_string(count) << std::endl;

  return 0;
}
