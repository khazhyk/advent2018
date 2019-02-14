#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

#include "fmt/format.h"

const char *input_file = "../res/input_2.txt";

std::pair<int, int> twos_and_threes(std::string &name) {
  std::map<char, int> char_to_count;
  bool two = false, three = false;

  for (char c : name) {
    char_to_count[c]++;
  }
  for (auto item : char_to_count) {
    if (item.second == 2) {
      two = 1;
    } else if (item.second == 3) {
      three = 1;
    }
  }

  return {two, three};
}

int main() {
  std::ifstream input{input_file};
  std::string line;

  if (input.fail()) {
    std::cerr << std::strerror(errno) << "\n";
  }

  int twos = 0, threes = 0;

  while (std::getline(input, line)) {
    auto two_and_three = twos_and_threes(line);

    fmt::print("Line: {}, twos: {} and threes: {}\n", line, two_and_three.first, two_and_three.second);

    twos += two_and_three.first;
    threes += two_and_three.second;
  }

  fmt::print("Twos: {} threes: {} chksum: {}\n", twos, threes, twos * threes);

  return 0;
}
