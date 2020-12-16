// Advent of Code 2020

#include <tuple>
#include <unordered_map>

#include "../helper-classes/list-reader.h"

namespace {

constexpr std::pair<int, int> empty_pair = {0, 0};

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
                << std::to_string(target_value) << "\n";
      return std::pair<int, int>(value, item->second);
    }
  }

  std::cout << "Unable to find 2sum pair for " << std::to_string(target_value)
            << "\n";
  return empty_pair;
}

std::tuple<int, int, int> Get3Sum(int target_sum, const std::vector<int>& int_list) {
  std::unordered_map<int, int> complement_map;
  for (int value : int_list) {
    complement_map.insert(std::pair<int, int>(target_sum - value, value));
  }

  for (const auto pair : complement_map) {
    const auto match = Get2Sum(pair.first, int_list, pair.second);

    if (match != empty_pair) {
      std::cout << "Found 3sum: " << std::to_string(match.first) << " + "
                << std::to_string(match.second) << " + "
                << std::to_string(pair.second) << " = "
                << std::to_string(target_sum) << "\n";
      return std::make_tuple(match.first, match.second, pair.second);
    }
  }

  std::cout << "Unable to find 3sum set.\n";
  return std::tuple<int, int, int>();
}

} // namespace

int main(int argc, char **argv) {
  int target_sum = 2020;

  std::string filepath(
    "C:/Users/grhousto/advent-of-code/day-01/advent-day-01-data.csv");
  std::vector<int> int_list = data::GetIntList(filepath);
  Get3Sum(target_sum, int_list);
}
