// Advent of Code 2020

#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

#include "../helper-classes/list-reader.h"

constexpr char filepath[] = "../day-10/advent-day-10-data.txt";

namespace {

std::vector<long long> GetInputList() {
  auto jolt_list = data::GetIntList(filepath);
  // Add the 0 joltage outlet to the list
  jolt_list.push_back(0);
  std::sort(jolt_list.begin(), jolt_list.end());
  // Add the actual device joltage to the end of the sorted list
  jolt_list.push_back(jolt_list[jolt_list.size() - 1] + 3);

  return jolt_list;
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &v) {
  for (const auto &val : v) {
    os << val << ", ";
  }
  return os;
}

std::ostream &operator<<(std::ostream &os,
                         const std::unordered_map<int, std::vector<int>> &map) {
  for (const auto &pair : map) {
    os << pair.first << ":" << pair.second << std::endl;
  }
  return os << std::endl;
}

long long
RecursiveDetermineNumPaths(const std::unordered_map<int, std::vector<int>> &map,
                           const int adapter) {
  static std::unordered_map<int /* adapter */, long long /* num paths */>
      seen_values;
  if (adapter == 0) {
    return 1;
  } else if (seen_values.find(adapter) != seen_values.end()) {
    return seen_values[adapter];
  }

  long long num_paths = 0;
  for (const auto &val : map.find(adapter)->second) {
    num_paths += RecursiveDetermineNumPaths(map, val);
  }
  seen_values[adapter] = num_paths;

  return num_paths;
}

} // namespace

std::pair<int, int>
CalculateJoltDifferences(const std::vector<long long> &jolt_list) {
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

long long
DetermineTotalNumJoltageConfigs(const std::vector<long long> jolt_list) {
  std::unordered_map<int /* adapter item */,
                     std::vector<int> /* lower adapters it can receive */>
      adapter_map;

  for (int i = 0; i < jolt_list.size() - 1; ++i) {
    for (int j = i + 1;
         j < jolt_list.size() && jolt_list[j] - jolt_list[i] <= 3; ++j) {
      if (adapter_map.find(jolt_list[j]) == adapter_map.end()) {
        adapter_map[jolt_list[j]] = std::vector<int>();
      }
      adapter_map.find(jolt_list[j])->second.push_back(jolt_list[i]);
    }
  }

  // std::cout << adapter_map;

  return RecursiveDetermineNumPaths(adapter_map,
                                    jolt_list[jolt_list.size() - 1]);
}

int main(int argc, char **argv) {
  auto jolt_list = GetInputList();

  const auto &jolt_diffs = CalculateJoltDifferences(jolt_list);
  std::cout << "Part 1 - 1:" << jolt_diffs.first << ", 3:" << jolt_diffs.second
            << std::endl;

  long long part2 = DetermineTotalNumJoltageConfigs(jolt_list);

  std::cout << "Part 2 - Total number of adapter paths: " << part2 << std::endl;

  return 0;
}
