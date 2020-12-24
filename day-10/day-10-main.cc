// Advent of Code 2020

#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

#include "../helper-classes/list-reader.h"

constexpr char filepath[] = "../day-10/advent-day-10-data.txt";

std::pair<int, int> CalculateJoltDifferences() {
  auto jolt_list = data::GetIntList(filepath);

  // Add the 0 joltage outlet to the list
  jolt_list.push_back(0);
  std::sort(jolt_list.begin(), jolt_list.end());
  // Add the actual device joltage to the end of the sorted list
  jolt_list.push_back(jolt_list[jolt_list.size() - 1] + 3);

  int one_diff = 0;
  int three_diff = 0;

  // Use iterator for practice using an iterator
  for (auto iter = jolt_list.begin() + 1; iter != jolt_list.end(); ++iter) {
    auto jolt_diff = *iter - *(iter - 1);
    assert(jolt_diff <= 3);
  
    if (jolt_diff == 1) {
      ++one_diff;
    } else if (jolt_diff == 3) {
      ++three_diff;
    }
  }

  return std::make_pair(one_diff, three_diff);
}


int main(int argc, char** argv) {
  const auto& jolt_diffs = CalculateJoltDifferences();

  std::cout << "Part 1 - 1:" << jolt_diffs.first << ", 3:" << jolt_diffs.second << std::endl;

  return 0;
}
