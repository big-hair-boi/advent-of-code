// Advent of Code

#include "csv_reader.h"

CSVReader::CSVReader(std::string filename, std::string delimiter)
        : _filename(filename), _delimiter(delimiter) {}

std::vector<std::vector<std::string>> CSVReader::GetData() {
    return std::vector<std::vector<std::string>>();
}
