cmake_minimum_required(VERSION 3.19.1)

# set the project name and version
project(advent-of-code)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_library(list-reader STATIC list-reader.h list-reader.cc)
#target_compile_definitions(list-reader PUBLIC list-reader)

add_library(int-list-reader STATIC int-list-reader.cc)
#target_link_libraries(int-list-reader PUBLIC list-reader)
#target_compile_definitions(int-list-reader PUBLIC int-list-reader)
