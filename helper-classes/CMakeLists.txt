cmake_minimum_required(VERSION 3.19.1)

# set the project name and version
project(advent-of-code)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(helper-classes STATIC csv_reader.cc)
