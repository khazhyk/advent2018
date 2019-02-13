#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

const char *input_file = "../res/input_1_1.txt";

int main() {
  std::ifstream input{input_file};
  std::string line;

  if (input.fail()) {
    std::cerr << std::strerror(errno) << "\n";
  }

  int total = 0;

  while (std::getline(input, line)) {
    int linenum;
    std::istringstream iss(line);
    if (!(iss >> linenum)) {
      break;
    }
    total += linenum;
  }

  std::cout << total << "\n";

  return 0;
}
