#include "day1.hpp"

#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <tuple>

int find_puzzle_answer_part_1(std::string data) {
  std::istringstream iss(data);
  std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
  int acc = 0;
  for(std::string token : results) {
    auto sign = token.substr (0,1);
    auto value = token.substr(1);
    auto int_val = std::stoi(value);

    if(sign == "+") {
      acc += int_val;
    } else if(sign == "-") {
      acc -= int_val;
    } else {
      throw std::exception("Cannot read sign");
    }
  }
  return acc;
}

std::tuple<bool, int> get_position_twice(int value, std::vector<int> values) {
  for(int val : values) {
    if(val == value) {
      return {true, val};
    }
  }
  return {false, 0};
}

std::tuple<int, std::vector<int>, bool> 
make_one_pass(std::vector<std::string> tokens, int acc, std::vector<int> values) {
  for(std::string token : tokens) {
    auto sign = token.substr (0,1);
    auto value = token.substr(1);
    auto int_val = std::stoi(value);

    auto twice = get_position_twice(acc, values);
    if(std::get<0>(twice)) {
      return {acc, values, true};
    }

    values.push_back(acc);

    if(sign == "+") {
      acc += int_val;
    } else if(sign == "-") {
      acc -= int_val;
    } else {
      throw std::exception("Cannot read sign");
    }
  }
  return {acc, values, false};
}

int find_puzzle_answer_part_2(std::string data, int acc) {
  std::istringstream iss(data);
  std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

  std::vector<int> values;
  int attempts = 0;
  bool found = false;

  while(attempts < 1000) {
    attempts++;
    std::tie(acc, values, found) = make_one_pass(results, acc, values);
    if(found) {
      return acc;
    }
  }

  throw std::exception("Couldn't find the repeating output");
}

int find_puzzle_answer_part_2(std::string data) {
  return find_puzzle_answer_part_2(data, 0);
}
