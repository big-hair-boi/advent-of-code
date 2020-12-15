// Advent of Code 2020

#include <unordered_map>

#include "../helper-classes/int-list-reader.h"

std::unique_ptr<std::pair<int, int>> Get2Sum(int target_value,
                                             std::vector<int> value_list,
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

    auto item = complement_map.find(value);
    if (item != complement_map.end() && value != item->second) {
      std::cout << "Found 2sum Pair: " << std::to_string(value) << " + "
                << std::to_string(item->second) << " = "
                << std::to_string(target_value) << "\n";
      return std::make_unique<std::pair<int, int>>(value, item->second);
    }
  }

  std::cout << "Unable to find 2sum pair for " << std::to_string(target_value)
            << "\n";
  return nullptr;
}

int main(int argc, char **argv) {
  data::IntListReader list_reader(
      "C:/Users/grhousto/advent-of-code/day-01/advent-day-01-data.csv");

  int target_sum = 2020;
  std::vector<int> int_list = list_reader.GetData();

  // Get2Sum(target_sum, int_list);
  std::unordered_map<int, int> complement_map;
  for (int value : int_list) {
    complement_map.insert(std::pair<int, int>(target_sum - value, value));
  }

  for (auto pair : complement_map) {
    auto match = Get2Sum(pair.first, int_list, pair.second);

    if (match) {
      std::cout << "Found 3sum: " << std::to_string(match.get()->first) << " + "
                << std::to_string(match.get()->second) << " + "
                << std::to_string(pair.second) << " = "
                << std::to_string(target_sum) << "\n";
      return 0;
    }
  }

  std::cout << "Unable to find 3sum set.\n";
  return 1;
}
