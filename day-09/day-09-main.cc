// Advent of Code 2020

#include <cassert>
#include <iostream>
#include <optional>

#include "../helper-classes/list-manipulation.h"
#include "../helper-classes/list-reader.h"

namespace {

constexpr const char filepath[] = "../day-09/advent-day-09-data.txt";

}

std::optional<int> FindXmasError(const std::vector<long long int> &data_list,
                                 int starting_index, int window_size) {
  for (int i = starting_index + window_size; i < data_list.size(); ++i) {
    const auto &possible2sum = compute::Get2Sum(
        data_list[i], std::vector<long long int>(data_list.begin() + i - window_size,
                                       data_list.begin() + i));
    if (possible2sum == compute::empty_2sum) {
      return data_list[i];
    }
  }

  return std::nullopt;
}

int main(int argc, char **argv) {
  const auto &int_list = data::GetIntList(filepath);
  const auto &part1_answer = FindXmasError(int_list, 0, 25);

  assert(part1_answer.has_value());
  std::cout << "Part 1 - first number to break 2sum rule: "
            << std::to_string(part1_answer.value()) << std::endl;

  return 0;
}
