#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  std::string line;
  std::ifstream kk("test.cols.txt", std::ios_base::in);
  while (std::getline(kk, line)) {

    std::cout << line << std::endl;
  }
}