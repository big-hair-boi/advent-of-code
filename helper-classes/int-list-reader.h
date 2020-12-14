// Advent of Code 2020

#ifndef HELPER_CLASSES_INT_LIST_READER_H_
#define HELPER_CLASSES_INT_LIST_READER_H_

#include "list-reader.h"

namespace data {

class IntListReader : public ListReader<int> {
  public:
    IntListReader(std::string filename) : ListReader<int>(filename) {}
    std::vector<int> GetData() override;
};

} // namespace data

#endif // HELPER_CLASSES_INT_LIST_READER_H_
