// Advent of Code 2020

#include <cassert>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>

#include "../helper-classes/list-reader.h"
#include "../helper-classes/string-manipulation.h"

using Operation = std::pair<std::string, int>;
using ExecutedOperation =
    std::tuple<Operation *, bool /* op changed */, int /* stack index */>;

constexpr const char filepath[] = "../day-08/advent-day-08-data.txt";
constexpr const char ACC[] = "acc";
constexpr const char JMP[] = "jmp";
constexpr const char NOP[] = "nop";
const std::unordered_set<std::string> valid_ops = {ACC, JMP, NOP};

namespace {

// Recursively determine value of accumulator, running the program from the
// operation at line |index|.
std::pair<int /* accumulator value */, bool /* has infinte loop been hit */>
RecursivelyFixProgram(const std::vector<Operation> &op_list,
                      std::unordered_set<int> &visited_ops, int index,
                      bool op_has_been_changed) {
  if (visited_ops.find(index) != visited_ops.end()) {
    // We've looped, so end the recursive search and update callers with the
    // status
    return std::make_pair(0, true);
  }
  if (index >= op_list.size()) {
    // We've finished the program, and should updates callers of the success
    return std::make_pair(0, false);
  }

  visited_ops.insert(index);
  Operation op = op_list[index];
  int local_acc = 0;

  int new_index = index + 1;
  if (op.first == ACC) {
    local_acc += op.second;
  } else if (op.first == JMP) {
    new_index += op.second - 1;
  }

  const auto &recursive_results = RecursivelyFixProgram(
      op_list, visited_ops, new_index, op_has_been_changed);
  if (recursive_results.second == true /* if infinite loop has been hit */) {
    if (op_has_been_changed || op.first != JMP) {
      visited_ops.erase(index);
      return recursive_results;
    } else {
      return RecursivelyFixProgram(op_list, visited_ops, index + 1, true);
    }
  } else {
    return std::make_pair(local_acc + recursive_results.first, false);
  }
}

} // namespace

std::ostream &operator<<(std::ostream &os, const Operation &op) {
  return os << op.first << ":" << std::to_string(op.second) << std::endl;
}

std::vector<Operation> BuildOpList() {
  std::vector<Operation> ret;
  for (const auto &line : data::GetStringList(filepath)) {
    const auto &op_data = data::string_split(line, " ");
    assert(op_data.size() == 2);

    // assume there are no errors in the data
    ret.push_back(std::make_pair(op_data[0], std::stoi(op_data[1])));
  }
  return ret;
}

void ComputePart1(const std::vector<Operation> &op_list) {
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

  std::cout << "Part 1 final accumulator value: " << std::to_string(acc)
            << std::endl;
}

void ComputePart2Recursive(const std::vector<Operation> &op_list) {
  std::unordered_set<int> visited_ops;

  const auto &value = RecursivelyFixProgram(op_list, visited_ops, 0, false);
  assert(value.second ==
         false /* validate there was eventually no recursive loop */);
  std::cout << "Part 2 - Final Accumulator value after fix: "
            << std::to_string(value.first);
}

int main(int argc, char **argv) {
  const auto &op_list = BuildOpList();
  ComputePart1(op_list);
  ComputePart2Recursive(op_list);
}
