#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

const char *input_file = "../res/input_1_1.txt";

int main(int argc, char **argv) {
  std::ifstream input{input_file};
  std::stringstream inputstream;
  inputstream << input.rdbuf();
  const std::string inputbuf{inputstream.str()};

  if (input.fail()) {
    std::cerr << std::strerror(errno) << "\n";
  }
  input.close();

  int total;
  std::string line;
  std::set<int64_t> seen;

  while (true) {
    std::istringstream inputstream2{inputbuf};

    while (std::getline(inputstream2, line)) {
      int64_t linenum;
      std::istringstream iss(line);
      if (!(iss >> linenum)) {
        break;
      }
      total += linenum;

      if (seen.find(total) != seen.end()) {
        std::cout << "Found match! " << total << "\n";
        return 0;
      }
      seen.insert(total);
    }
  }
}
