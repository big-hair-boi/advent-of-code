cmake_minimum_required(VERSION 3.19.1)

# set the project name and version
project(advent-of-code)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# create object files for general reading in of list data
add_library(list-reader STATIC list-reader.cc)
