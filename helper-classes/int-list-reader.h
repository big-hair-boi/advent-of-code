// Advent of Code 2020

#include "list-reader.h"

namespace data {

class IntListReader : public ListReader<int> {
  public:
    IntListReader(std::string filename) : ListReader<int>(filename) {}
    std::vector<int> GetData() override;
};

} // namespace data
