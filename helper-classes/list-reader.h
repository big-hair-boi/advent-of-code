// Advent of Code 2020

#include <string>
#include <vector>

namespace data {

template <typename data_type>
class ListReader {
  public:
    ListReader(std::string filename) : _filename(filename) {}
    ~ListReader() = default;
    ListReader(const ListReader&) = delete;
    ListReader& operator=(const ListReader&) = delete;

    virtual std::vector<data_type> GetData() = 0;

  protected:
    std::string _filename;
};

class ListReaderImpl : ListReader<std::string> {
    // Default implementation returns a list of strings
    std::vector<std::string> GetData() override;
};

} // namespace data
