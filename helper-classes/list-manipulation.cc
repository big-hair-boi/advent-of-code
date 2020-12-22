// Advent of Code 2020

#include "../helper-classes/list-manipulation.h"

#include <iostream>
#include <string>
#include <unordered_map>


namespace compute {

std::pair<int, int> Get2Sum(int target_value,
                            const std::vector<int>& value_list,
                            int used_value = INT_MIN) {
  // build the complement map
  std::unordered_map<int, int> complement_map;
  for (int value : value_list) {
    if (value == used_value)
      continue;
    complement_map.insert(std::pair<int, int>(target_value - value, value));
  }

  for (int value : value_list) {
    if (value == used_value)
      continue;

    const auto item = complement_map.find(value);
    if (item != complement_map.end() && value != item->second) {
      std::cout << "Found 2sum Pair: " << std::to_string(value) << " + "
                << std::to_string(item->second) << " = "
                << std::to_string(target_value) << std::endl;
      return std::pair<int, int>(value, item->second);
    }
  }

  std::cout << "Unable to find 2sum pair for " << std::to_string(target_value)
            << std::endl;
  return empty_2sum;
}

std::tuple<int, int, int> Get3Sum(int target_sum, const std::vector<int>& int_list) {
  std::unordered_map<int, int> complement_map;
  for (int value : int_list) {
    complement_map.insert(std::pair<int, int>(target_sum - value, value));
  }

  for (const auto pair : complement_map) {
    const auto match = Get2Sum(pair.first, int_list, pair.second);

    if (match != empty_2sum) {
      std::cout << "Found 3sum: " << std::to_string(match.first) << " + "
                << std::to_string(match.second) << " + "
                << std::to_string(pair.second) << " = "
                << std::to_string(target_sum) << std::endl;
      return std::make_tuple(match.first, match.second, pair.second);
    }
  }

  std::cout << "Unable to find 3sum set." << std::endl;
  return empty_3sum;
}

} // namespace compute
