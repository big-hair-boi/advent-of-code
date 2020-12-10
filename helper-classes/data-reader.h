// Advent of Code 2020

#include <string>
#include <vector>

template <typename data_type>
class DataReader {
  public:
    DataReader(std::string filename) : _filename(filename) {}
    ~DataReader() = default;
    DataReader(const DataReader&) = delete;
    DataReader& operator=(const DataReader&) = delete;

    virtual std::vector<data_type> GetData() = 0;

  protected:
    std::string _filename;
};

class DataReaderImpl : DataReader<std::string> {
    // Default implementation returns a list of strings
    std::vector<std::string> GetData() override;
};
