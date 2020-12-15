// Advent of Code 2020

#ifndef HELPER_CLASSES_LIST_READER_H_
#define HELPER_CLASSES_LIST_READER_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace data {

template <typename data_type> class ListReader {
public:
  ListReader(std::string filename) : _filename(filename) {}
  ~ListReader() = default;
  ListReader(const ListReader &) = delete;
  ListReader &operator=(const ListReader &) = delete;

  virtual std::vector<data_type> GetData() = 0;

protected:
  std::string _filename;
  inline std::vector<std::string> GetStringListData() {
    std::vector<std::string> data_list;

    std::ifstream file(this->_filename);
    if (!file)
      std::cout << "File couldn't be opened\n";

    std::string str;
    while (std::getline(file, str)) {
      data_list.push_back(str);
    }
    file.close();

    return data_list;
  }
};

class ListReaderImpl : ListReader<std::string> {
public:
  ListReaderImpl(std::string filename) : ListReader(filename) {}

  // Default implementation returns a list of strings
  std::vector<std::string> GetData() override {
    return this->GetStringListData();
  };
};

} // namespace data

#endif // HELPER_CLASSES_LIST_READER_H_
