#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "fmt/format.h"

const char *input_file = "../res/input_2.txt";

int num_diff(std::string &one, std::string &two) {
  auto iter_one = one.begin();
  auto iter_two = two.begin();

  int similar = 0;

  while (iter_one != one.end() && iter_two != one.end()) {
    if (*iter_one != *iter_two) similar++;
    ++iter_one;
    ++iter_two;
  }
  return similar;
}

int main() {
  std::ifstream input{input_file};
  std::string line;

  if (input.fail()) {
    std::cerr << std::strerror(errno) << "\n";
  }

  std::vector<std::string> lines;

  while (std::getline(input, line)) {
    lines.push_back(line);
  }

  // lmao
  for (auto line : lines) {
    for (auto line_inner : lines) {
      auto diff = num_diff(line, line_inner);
      if (diff == 1){
       fmt::print("{}, {}, {}\n", line, line_inner, diff);
      }
    }
  }

  return 0;
}
