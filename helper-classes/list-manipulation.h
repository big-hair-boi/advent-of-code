// Advent of Code 2020

#ifndef HELPER_CLASSES_LIST_MANIPULATION_H_
#define HELPER_CLASSES_LIST_MANIPULATION_H_

#include <tuple>
#include <utility>
#include <vector>

namespace compute {

constexpr const std::pair<long long int, long long int> empty_2sum = {0, 0};
constexpr const std::tuple<long long int, long long int, long long int> empty_3sum = {0, 0, 0};

std::pair<long long int, long long int> Get2Sum(long long int target_value,
                            const std::vector<long long int>& value_list,
                            long long int used_value = INT_MIN);
std::tuple<long long int, long long int, long long int> Get3Sum(long long int target_sum,
                                  const std::vector<long long int>& int_list);

} // namespace compute
#endif // HELPER_CLASSES_LIST_MANIPULATION_H_
