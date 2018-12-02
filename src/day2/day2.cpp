#include <iterator>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>

#include "day2.hpp"

// abcdef

std::unordered_map<char, int> count_chars(std::string input) {
  std::unordered_map<char, int> values;
  for(char c : input) {
    auto it = values.find(c);
    if(it != values.end()) {
      it->second++;
    } else {
      values[c] = 1;
    }
  }

  return values;
}

std::tuple<bool, bool> find_two_and_three(std::string input) {
  auto values = count_chars(input);
  bool has_two = false;
  bool has_three = false;

  for(auto item : values) {
    if(item.second == 3) {
      has_three = true;
    } else if (item.second == 2) {
      has_two = true;
    }
  }

  return {has_two, has_three};
}

int find_puzzle_answer_part_1(std::string input) {
  std::istringstream iss(input);
  std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

  int count_twos = 0;
  int count_threes = 0;

  for(auto line : results) {
    int twos, threes;
    std::tie(twos, threes) = find_two_and_three(line);
    count_twos += twos;
    count_threes += threes;
  }

  return count_twos * count_threes;
}

int count_different_letters(std::string string1, std::string string2) {
  int count = 0;

  for(int i = 0; i < string1.length(); i++) {
    if(string1.at(i) != string2.at(i)) {
      count++;
    }
  }

  return count;
}

std::string find_same_letters(std::string string1, std::string string2) {
  std::string retstr = "";
  for(int i = 0; i < string1.length(); i++) {
    if(string1.at(i) == string2.at(i)) {
      retstr += string1.at(i);
    }
  }
  return retstr;
}

std::string find_puzzle_answer_part_2(std::string input) {
  std::istringstream iss(input);
  std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

  for(auto string1 : results) {
    for(auto string2 : results) {
      if(string1 == string2) {
        continue;
      }

      if(count_different_letters(string1, string2) == 1) {
        return find_same_letters(string1, string2);
      }
    }
  }
  throw std::exception("Couldn't find the string");
}
