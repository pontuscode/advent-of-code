cmake_minimum_required(VERSION 3.16)
project(AoC_2025_Day2)
set(CMAKE_CXX_STANDARD 20)

# Tell CMake to look in Conan's generated files
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
find_package(argparse REQUIRED)
find_package(Catch2 REQUIRED)
find_package(logger REQUIRED)

add_executable(day1_2025
    src/main.cpp
    src/dial.cpp
)
target_link_libraries(day1_2025 PRIVATE
    argparse::argparse
    logger::logger
)
target_include_directories(day1_2025 PRIVATE
    "include"
)
