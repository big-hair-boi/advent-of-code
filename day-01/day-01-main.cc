// Advent of Code 2020

#include <tuple>
#include <unordered_map>

#include "../helper-classes/list-manipulation.h"
#include "../helper-classes/list-reader.h"

constexpr std::pair<int, int> empty_pair = {0, 0};
namespace {} // namespace

int main(int argc, char **argv) {
  long int target_sum = 2020;

  constexpr char filepath[] = "../day-01/advent-day-01-data.csv";

  const auto &int_list = data::GetIntList(filepath);
  compute::Get3Sum(target_sum, int_list);
}
