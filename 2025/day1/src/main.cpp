#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <format>
#include "dial.h"
#include "logger.h"
#include "argparse/argparse.hpp"


int main(int argc, char* argv[]) {
    argparse::ArgumentParser program("AoC 2025 - Day 1");
    program.add_argument("-v", "--verbose")
        .help("increase logging verbosity")
        .default_value(false)
        .implicit_value(true);
    program.add_argument("-i", "--input-file")
        .help("path to input file")
        .default_value("./input.txt");

    try {
        program.parse_args(argc, argv);
    } catch(const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }
    Logger logger = Logger();
    if(program.get<bool>("verbose")) {
        logger.setLevel(DEBUG);
    }
    std::vector<std::string> input{};
    std::string const inputFile = program.get<std::string>("input-file");
    logger.info(std::format("Input file: {}", inputFile));
    logger.debug("Converting input file to path");

    std::filesystem::path ip = std::filesystem::path(inputFile);
    if(!std::filesystem::exists(ip)) {
        logger.critical(std::format("Input file {} doesn't exist!", inputFile));
    }

    std::string line;
    std::ifstream file(ip);
    while(std::getline(file, line)) {
        input.push_back(line);
    }

    Dial dial = Dial();
    Direction direction;
    int numberOfZeroes = 0;

    for(const auto& line : input) {
        if(dial.rotate(line)) {
            numberOfZeroes++;
        }
    }
    logger.info(std::format("Number of zeroes: {}", numberOfZeroes));
}
