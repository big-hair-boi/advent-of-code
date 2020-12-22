// Advent of Code 2020

#ifndef HELPER_CLASSES_LIST_MANIPULATION_H_
#define HELPER_CLASSES_LIST_MANIPULATION_H_

#include <tuple>
#include <utility>
#include <vector>

namespace compute {

constexpr const std::pair<int, int> empty_2sum = {0, 0};
constexpr const std::tuple<int, int, int> empty_3sum = {0, 0, 0};

std::pair<int, int> Get2Sum(int target_value,
                            const std::vector<int>& value_list,
                            int used_value);
std::tuple<int, int, int> Get3Sum(int target_sum,
                                  const std::vector<int>& int_list);

} // namespace compute
#endif // HELPER_CLASSES_LIST_MANIPULATION_H_
