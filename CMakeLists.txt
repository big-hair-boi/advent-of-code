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
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(ClangFormat.cmake)

# Add sub-directories
add_subdirectory(./helper-classes)

# day-01 solution
add_executable(day-01-main ./day-01/day-01-main.cc)
target_link_libraries(day-01-main PUBLIC int-list-reader)


# Setup clang-format and generate a "format" target
# find_program(CLANG_FORMAT "clang-format")
# if(CLANG_FORMAT)
#     message("test printing inside if statement")
#     file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
#         ${PROJECT_SOURCE_DIR}/*.cc 
#     )
#     file(GLOB_RECURSE ALL_CXX_HEADER_FILES
#         ${PROJECT_SOURCE_DIR}/*.h
#     )
#     message(${ALL_CXX_SOURCE_FILES})
#     message(${ALL_CXX_HEADER_FILES})

#     add_custom_target(
#         TARGET format
#         COMMAND clang-format
#         -i
#         -style=file
#         ${ALL_CXX_SOURCE_FILES}
#     )
# endif()
