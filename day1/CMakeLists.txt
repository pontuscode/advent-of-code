cmake_minimum_required(VERSION 3.16)
project(AoC_Day1)

# Tell CMake to look in Conan's generated files
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
find_package(argparse REQUIRED)
find_package(Catch2 REQUIRED)
find_package(logger REQUIRED)

add_executable(day1 src/main.cpp)
target_link_libraries(day1 argparse::argparse logger::logger)

# Add test executable
add_executable(tests test/test_day1.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain argparse::argparse)

include(CTest)
include(Catch)
catch_discover_tests(tests)
