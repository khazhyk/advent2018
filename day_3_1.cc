#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

#include "fmt/format.h"

const char *input_file = "../res/input_3.txt";

struct box {
  int left;
  int top;
  int width;
  int height; 
};

int main() {
  std::ifstream input{input_file};
  std::string line;
  std::regex line_re{"#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)"};

  if (input.fail()) {
    std::cerr << std::strerror(errno) << "\n";
    return -1;
  }
  // Well here's one way to do it
  std::vector<std::array<uint8_t, 1000>> bitmap(1000);
  int overlap = 0;

  while (std::getline(input, line)) {
    std::smatch items;
    std::regex_match(line, items, line_re);
    box bo{
      std::stoi(items[2]),
      std::stoi(items[3]),
      std::stoi(items[4]),
      std::stoi(items[5])
    };

    for (int i = bo.left; i < bo.left + bo.width; i++) {
      for (int j = bo.top; j < bo.top + bo.height; j++) {
        bitmap[i][j] += 1;
        if (bitmap[i][j] == 2) {
          overlap++;
        }
      }
    }
  }
  fmt::print("{}\n", overlap);

  return 0;
}
