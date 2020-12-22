// Advent of Code 2020

#include "../helper-classes/list-manipulation.h"

#include <iostream>
#include <string>
#include <unordered_map>

namespace compute {

std::pair<long long int, long long int>
Get2Sum(long long int target_value,
        const std::vector<long long int> &value_list,
        long long int used_value) {
  // build the complement map
  std::unordered_map<long long int, long long int> complement_map;
  for (const auto &value : value_list) {
    if (value == used_value)
      continue;
    complement_map.insert(
        std::pair<long long int, long long int>(target_value - value, value));
  }

  for (const auto &value : value_list) {
    if (value == used_value)
      continue;

    const auto &item = complement_map.find(value);
    if (item != complement_map.end() && value != item->second) {
      return std::pair<long long int, long long int>(value, item->second);
    }
  }

  return empty_2sum;
}

std::tuple<long long int, long long int, long long int>
Get3Sum(long long int target_sum, const std::vector<long long int> &int_list) {
  std::unordered_map<long long int, long long int> complement_map;
  for (const auto &value : int_list) {
    complement_map.insert(
        std::pair<long long int, long long int>(target_sum - value, value));
  }

  for (const auto &pair : complement_map) {
    const auto match = Get2Sum(pair.first, int_list, pair.second);

    if (match != empty_2sum) {
      return std::make_tuple(match.first, match.second, pair.second);
    }
  }

  return empty_3sum;
}

} // namespace compute
