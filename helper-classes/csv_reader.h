// Advent of Code
//
// CSV Reader class helper class to import data for challenges.
// Takes CSV file and returns an std::vector

#include <string>
#include <vector>

class CSVReader {
  public:
    explicit CSVReader(std::string filename, std::string delimiter = ",");
    ~CSVReader() = default;
    CSVReader(const CSVReader&) = delete;
    CSVReader& operator=(const CSVReader&) = delete;

    std::vector<std::vector<std::string>> GetData();

  private:
    std::string _filename;
    std::string _delimiter;
};