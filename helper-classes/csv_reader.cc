// Advent of Code

#include "csv_reader.h"

CSVReader::CSVReader(std::string filename, std::string delimiter)
        : _filename(filename), _delimiter(delimiter) {}

std::unique_ptr<std::vector<std::vector<std::string>>> CSVReader::GetData() {
    return std::move(std::make_unique<std::vector<std::vector<std::string>>>());
}
