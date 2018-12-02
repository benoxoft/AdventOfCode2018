#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

// #include <direct.h>
// #define GetCurrentDir _getcwd

std::string slurp(std::ifstream& in) {
    if(in.good()) {
        std::stringstream sstr;
        sstr << in.rdbuf();
        return sstr.str();
    } else {
        throw std::exception("Invalid file");
    }
}

std::string get_puzzle_input(int day) {
    std::string input = slurp(std::ifstream("puzzle_inputs/day" + std::to_string(day) + ".txt", std::ifstream::in));
    return input;
}

/* 
std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}
*/