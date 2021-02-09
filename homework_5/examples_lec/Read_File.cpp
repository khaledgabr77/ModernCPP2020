#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

int main() {
  int value;
  std::ifstream in("test_cols.txt", std::ios_base::in);
  while (in >> value) {
    std::cout << value << std::endl;
  }
}