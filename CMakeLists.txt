cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 17)

project(AdventOfCode)

add_subdirectory(lib/Catch2)

include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)
