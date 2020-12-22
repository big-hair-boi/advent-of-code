// Advent of Code 2020

#include <cassert>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include "../helper-classes/list-reader.h"
#include "../helper-classes/string-manipulation.h"


using Operation = std::pair<std::string, int>;

constexpr const char filepath[] = "../day-08/advent-day-08-data.txt";
constexpr const char ACC[] = "acc";
constexpr const char JMP[] = "jmp";
constexpr const char NOP[] = "nop";
const std::unordered_set<std::string> valid_ops = {ACC, JMP, NOP};

namespace {

std::ostream& operator<<(std::ostream& os, const Operation& op) {
  return os << op.first << ":" << std::to_string(op.second) << std::endl;
}

} // namespace

std::vector<Operation> BuildOpList() {
  std::vector<Operation> ret;
  for (const auto& line : data::GetStringList(filepath)) {
    const auto& op_data = data::string_split(line, ' ');
    assert(op_data.size() == 2);

    // assume there are no errors in the data
    ret.push_back(std::make_pair(op_data[0], std::stoi(op_data[1])));
  }
  return ret;
}

void ComputePart1(const std::vector<Operation>& op_list) {
  std::unordered_set<int> visited_ops;
  int acc = 0;

  int index = 0;
  while (visited_ops.find(index) == visited_ops.end()) {
    std::string op = op_list[index].first;
    int value = op_list[index].second;

    assert(valid_ops.find(op) != valid_ops.end());
    visited_ops.insert(index);

    if (op == JMP) {
      index += value;
      continue;
    } else if (op == ACC) {
      acc += value;
    }
    ++index;
  }

  std::cout << "Part 1 final accumulator value: " << std::to_string(acc) << std::endl;
}

int main(int argc, char** argv) {
  const auto& op_list = BuildOpList();
  ComputePart1(op_list);
}
