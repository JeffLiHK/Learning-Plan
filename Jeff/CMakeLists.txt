project(Jeff_Code)

set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.20)

add_executable(test Test/test.cpp)

include_directories(Util)
link_directories(Util)
#add_subdirectory(Util)

add_executable(sort_test Sorting/sort_test.cpp Sorting/bubble_sort.cpp Util/util.cpp)