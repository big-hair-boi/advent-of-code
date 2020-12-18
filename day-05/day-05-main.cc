// Advent of Code 2020

#include <algorithm>
#include <cmath>
#include <vector>

#include "../helper-classes/list-reader.h"

constexpr char filepath[] = "../day-05/advent-day-05-data.txt";

// convention: row, column
using Seat = std::pair<int, int>;

namespace {

int BinarySearchHelper(const std::string &search_commands, char move_left,
                       char move_right, int max_value) {
  // |left| ins inclusive whereas |right| is not
  int left = 0;
  int right = max_value + 1;

  for (int i = 0; i < search_commands.size(); ++i) {
    int *bounds_to_alter;
    if (search_commands[i] == move_left)
      bounds_to_alter = &right;
    else if (search_commands[i] == move_right)
      bounds_to_alter = &left;
    else {
      std::cout << "ERROR: invalid move command '" << search_commands[i] << "'"
                << std::endl;
      return -1;
    }
    *bounds_to_alter = (left + right) / 2;
  }
  if (right - left != 1) {
    std::cout << "ERROR: " << std::to_string(left) << "+1"
              << "!=" << std::to_string(right) << std::endl;
    return -2;
  }

  return left;
}

int GetSeatID(const Seat &seat) { return seat.first * 8 + seat.second; }

} // namespace

Seat DetermineSeat(const std::string &seat_code) {
  int boundary = 7;
  return std::make_pair(
      BinarySearchHelper(seat_code.substr(0, boundary), 'F', 'B', 127),
      BinarySearchHelper(seat_code.substr(boundary, boundary + 3), 'L', 'R',
                         7));
}

std::ostream &operator<<(std::ostream &os, const Seat &s) {
  return os << "r:" << s.first << ","
            << "c:" << s.second << ","
            << "id:" << std::to_string(GetSeatID(s)) << std::endl;
}

int main(int argc, char **argv) {
  std::vector<int /* IDs */> id_list;
  int max_id = INT_MIN;
  int min_id = INT_MAX;

  for (const auto &seat_code : data::GetStringList(filepath)) {
    std::cout << "Seat code: '" << seat_code << "'" << std::endl;
    Seat seat = DetermineSeat(seat_code);
    std::cout << seat << std::endl << std::endl;

    int id = GetSeatID(seat);
    id_list.push_back(id);

    if (id > max_id)
      max_id = id;
    if (id < min_id)
      min_id = id;
  }
  std::cout << "Part 1 - Max Seat ID = " << std::to_string(max_id) << std::endl;

  std::sort(id_list.begin(), id_list.end());
  for (int i = 1; i < id_list.size(); ++i) {
    if (id_list[i] - id_list[i - 1] != 1) {
      std::cout << "Part 2 - Found Seat ID: " << std::to_string(id_list[i] - 1)
                << std::endl;
      break;
    }
  }

  return 0;
}
