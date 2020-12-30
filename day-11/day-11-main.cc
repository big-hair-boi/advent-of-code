// Advent of Code

#include <array>
#include <vector>

#include "../helper-classes/list-reader.h"

namespace {

constexpr const char filepath[] = "../day-11/advent-day-11-data.txt";
constexpr int row_length = 98;

template <typename T> using SeatMatrix = std::vector<std::array<T, row_length>>;

SeatMatrix<int> CalculateAdjacentSeatsPart1(const SeatMatrix<char> &seats) {
  SeatMatrix<int> ret;

  for (int i = 0; i < seats.size(); ++i) {
    std::array<int, row_length> occupied_seats{0};

    for (int j = 0; j < row_length; ++j) {
      // only need to calculate adjacency for actual seats
      if (seats[i][j] == '.') {
        continue;
      }

      // Iterate over 3x3 square to calculate number of adjacent seats
      int num_adjacent = 0;
      for (int row = i - 1; row <= i + 1; ++row) {
        for (int column = j - 1; column <= j + 1; ++column) {
          if (row >= 0 && row < seats.size() && column >= 0 &&
              column < row_length && (row - i != 0 || column - j != 0)) {
            num_adjacent += seats[row][column] == '#' ? 1 : 0;
          }
        }
      }
      occupied_seats[j] = num_adjacent;
    }

    ret.push_back(occupied_seats);
  }

  return ret;
}

SeatMatrix<int> CalculateAdjacentSeatsPart2(const SeatMatrix<char> &seats) {
  SeatMatrix<int> ret;

  for (int i = 0; i < seats.size(); ++i) {
    std::array<int, row_length> occupied_seats{0};

    for (int j = 0; j < row_length; ++j) {
      // only need to calculate adjacency for actual seats
      if (seats[i][j] == '.') {
        continue;
      }

      // Iterate over 3x3 square to calculate number of adjacent seats
      int num_adjacent = 0;
      for (int y_dir = i - 1; y_dir <= i + 1; ++y_dir) {
        for (int x_dir = j - 1; x_dir <= j + 1; ++x_dir) {
          if (y_dir - i == 0 && x_dir - j == 0) {
            continue;
          }

          int row = y_dir;
          int column = x_dir;
          while (true) {
            if (row < 0 || row >= seats.size() || column < 0 ||
                column >= row_length) {
              break;
            }

            if (seats[row][column] == 'L' || seats[row][column] == '#') {
              num_adjacent += seats[row][column] == '#' ? 1 : 0;
              break;
            } else {
              row += (y_dir - i);
              column += (x_dir - j);
            }
          }
        }
      }
      occupied_seats[j] = num_adjacent;
    }

    ret.push_back(occupied_seats);
  }

  return ret;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const SeatMatrix<T> &seats) {
  for (int i = 0; i < seats.size(); ++i) {
    for (int j = 0; j < row_length; ++j) {
      os << seats[i][j] << ",";
    }
    os << std::endl;
  }
  return os;
}

} // namespace

SeatMatrix<char> ReadSeatFormationFromFile() {
  std::vector<std::array<char, row_length>> ret;

  for (const auto &line : data::GetStringList(filepath)) {
    std::array<char, row_length> row;
    for (int i = 0; i < row_length; ++i) {
      row[i] = line[i];
    }
    ret.push_back(row);
  }
  return ret;
}

int CalculateNumEmptySeatsPart1(SeatMatrix<char> seats) {
  // Explicitly take a copy in the argument so that the original is not changed

  int num_changes = 1;
  while (num_changes > 0) {
    num_changes = 0;

    auto adjacency_data = CalculateAdjacentSeatsPart1(seats);
    for (int i = 0; i < seats.size(); ++i) {
      for (int j = 0; j < row_length; ++j) {
        if (seats[i][j] == '.') {
          continue;
        }

        if (seats[i][j] == '#' && adjacency_data[i][j] >= 4) {
          ++num_changes;
          seats[i][j] = 'L';
        } else if (seats[i][j] == 'L' && adjacency_data[i][j] == 0) {
          ++num_changes;
          seats[i][j] = '#';
        }
      }
    }
  }

  int ret = 0;
  for (int i = 0; i < seats.size(); ++i) {
    for (int j = 0; j < row_length; ++j) {
      if (seats[i][j] == '#') {
        ++ret;
      }
    }
  }

  return ret;
}

int CalculateNumEmptySeatsPart2(SeatMatrix<char> seats) {
  // Explicitly take a copy in the argument so that the original is not changed

  int num_changes = 1;
  while (num_changes > 0) {
    num_changes = 0;

    auto adjacency_data = CalculateAdjacentSeatsPart2(seats);
    for (int i = 0; i < seats.size(); ++i) {
      for (int j = 0; j < row_length; ++j) {
        if (seats[i][j] == '.') {
          continue;
        }

        if (seats[i][j] == '#' && adjacency_data[i][j] >= 5) {
          ++num_changes;
          seats[i][j] = 'L';
        } else if (seats[i][j] == 'L' && adjacency_data[i][j] == 0) {
          ++num_changes;
          seats[i][j] = '#';
        }
      }
    }
  }

  int ret = 0;
  for (int i = 0; i < seats.size(); ++i) {
    for (int j = 0; j < row_length; ++j) {
      if (seats[i][j] == '#') {
        ++ret;
      }
    }
  }

  return ret;
}

int main(int argc, char **argv) {
  auto seat_data = ReadSeatFormationFromFile();

  std::cout << "Part 1 - Final number of taken seats: "
            << CalculateNumEmptySeatsPart1(seat_data) << std::endl;
  std::cout << "Part 2 - Final number of taken seats: "
            << CalculateNumEmptySeatsPart2(seat_data) << std::endl;
}
