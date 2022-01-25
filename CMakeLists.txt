cmake_minimum_required(VERSION 3.17)
project(PolishNotation)

add_subdirectory(googletest-master)
include_directories(googletest-master/googletest/include)
include_directories(googletest-master/googlemock/include)

set(CMAKE_CXX_STANDARD 14)

add_executable(PolishNotation main.cpp PolishNotation.h)
target_link_libraries(PolishNotation gtest gtest_main)

