// Advent of Code 2020

#include <cassert>
#include <iostream>
#include <numeric>
#include <optional>
#include <queue>

#include "../helper-classes/list-manipulation.h"
#include "../helper-classes/list-reader.h"

namespace {

constexpr const char filepath[] = "../day-09/advent-day-09-data.txt";

long long queue_sum(std::queue<long long> window) {
  // queue is intentionally a copy
  long long ret = 0;
  while (!window.empty()) {
    ret += window.front();
    window.pop();
  }
  return ret;
}

std::vector<long long> queue_to_vector(std::queue<long long> window) {
  std::vector<long long> ret;
  while (!window.empty()) {
    ret.push_back(window.front());
    window.pop();
  }
  return ret;
}

} // namespace 

using Value = std::pair<long long /* value */, int /* index */>;
using WindowSum = std::queue<long long>;

std::ostream& operator<<(std::ostream& os, const Value& value) {
  return os << std::to_string(value.first) << ":" << std::to_string(value.second);
}

std::ostream& operator<<(std::ostream& os, WindowSum window) {
  // the WindowSum argument is intentionally a copy
  while (!window.empty()) {
    os << window.front() << ", ";
    window.pop();
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<long long> list) {
  for (const auto& val : list)
    os << std::to_string(val) << ", ";
  return os;
}

std::optional<Value> FindXmasError(const std::vector<long long int> &data_list,
                                 int starting_index, int window_size) {
  for (int i = starting_index + window_size; i < data_list.size(); ++i) {
    const auto &possible2sum = compute::Get2Sum(
        data_list[i],
        std::vector<long long int>(data_list.begin() + i - window_size,
                                   data_list.begin() + i));
    if (possible2sum == compute::empty_2sum) {
      return std::make_pair(data_list[i], i);
    }
  }

  return std::nullopt;
}

WindowSum FindWindowSum(const std::vector<long long> &data_list, const Value& target_value) {
  WindowSum window;

  // Create a moving window that grows in size as values become longer
  for (int i = target_value.second - 1; i >= 0; --i) {
    window.push(data_list[i]);
    auto window_sum = queue_sum(window);
    if (window_sum == target_value.first) {
      break;
    } else if (window_sum > target_value.first) {
      window.pop();
    }
  }

  return window;
}

int main(int argc, char **argv) {
  const auto &int_list = data::GetIntList(filepath);
  const auto &part1_answer = FindXmasError(int_list, 0, 25);

  assert(part1_answer.has_value());
  std::cout << "Part 1 - first number to break 2sum rule: "
            << part1_answer.value() << std::endl;

  WindowSum part2_answer = FindWindowSum(int_list, part1_answer.value());
  std::vector<long long> sorted_window = queue_to_vector(part2_answer);
  std::sort(sorted_window.begin(), sorted_window.end());
  //std::cout << "Part 2 - window sum: " << part2_answer << std::endl;
  //std::cout << "Part 2 - sorted window: " << part2_answer << std::endl;
  std::cout << "Part 2 - " << std::to_string(sorted_window[0] + sorted_window[sorted_window.size() - 1]) << std::endl;

  return 0;
}
