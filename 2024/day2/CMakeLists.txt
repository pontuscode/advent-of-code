cmake_minimum_required(VERSION 3.12)
project(AoC_Day2)

# Tell CMake to look in Conan's generated files
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
find_package(argparse REQUIRED)
find_package(Catch2 REQUIRED)
find_package(logger REQUIRED)

add_executable(day2 
    src/main.cpp
    src/report.cpp
)
target_link_libraries(day2 PRIVATE
    argparse::argparse
    logger::logger
)
target_include_directories(day2 PRIVATE
    "include"
)

# Add test executable
add_executable(tests test/test_day2.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain argparse::argparse)

include(CTest)
include(Catch)
catch_discover_tests(tests)
