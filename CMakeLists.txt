cmake_minimum_required(VERSION 3.19.1)

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

set(CMAKE_AR "llvm-ar" CACHE FILEPATH "" FORCE)

# set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang.exe")
# set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang.exe")
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# set the project name and version
project(advent-of-code VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add sub-directories
add_subdirectory(./helper-classes)

add_executable(day-01-main ./day-01/day-01-main.cc)

target_link_libraries(day-01-main PUBLIC list-reader)