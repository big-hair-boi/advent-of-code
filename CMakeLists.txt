cmake_minimum_required(VERSION 3.19.1)

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

set(CMAKE_AR "llvm-ar" CACHE FILEPATH "" FORCE)
set(CMAKE_LINKER "lld-link" CACHE FILEPATH "" FORCE)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# set the project name and version
project(advent-of-code VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wcall-to-pure-virtual-from-ctor-dtor")

include(ClangFormat.cmake)

# Add sub-directories
add_subdirectory(./helper-classes)

# day-01 solution
add_executable(day-01-main ./day-01/day-01-main.cc)
target_link_libraries(day-01-main PUBLIC list-reader)
target_link_libraries(day-01-main PUBLIC list-manipulation)

# day-04 solution
add_executable(day-04-main ./day-04/day-04-main.cc)
target_link_libraries(day-04-main PUBLIC string-manipulation)
target_link_libraries(day-04-main PUBLIC list-reader)

# day-05 solution
add_executable(day-05-main ./day-05/day-05-main.cc)
target_link_libraries(day-05-main PUBLIC list-reader)

# day-06 solution
add_executable(day-06-main ./day-06/day-06-main.cc)
target_link_libraries(day-06-main PUBLIC list-reader)

# day-07 solution
add_executable(day-07-main ./day-07/day-07-main.cc)
target_link_libraries(day-07-main PUBLIC string-manipulation)
target_link_libraries(day-07-main PUBLIC list-reader)

# day-08 solution
add_executable(day-08-main ./day-08/day-08-main.cc)
target_link_libraries(day-08-main PUBLIC string-manipulation)
target_link_libraries(day-08-main PUBLIC list-reader)

# day-09 solution
add_executable(day-09-main ./day-09/day-09-main.cc)
target_link_libraries(day-09-main PUBLIC list-manipulation)
target_link_libraries(day-09-main PUBLIC list-reader)

# day-10 solution
add_executable(day-10-main ./day-10/day-10-main.cc)
target_link_libraries(day-10-main PUBLIC list-reader)

# day-11 solution
add_executable(day-11-main ./day-11/day-11-main.cc)
target_link_libraries(day-11-main PUBLIC list-reader)
