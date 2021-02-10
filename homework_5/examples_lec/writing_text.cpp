#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::string filename("out.txt");
  std::ofstream kk(filename);
  if (!kk.is_open()) {
    return EXIT_FAILURE;
  }
  double a = 1.123456;
  kk << "Just String" << std::endl;
  kk << std::setprecision(20) << a << std::endl;
  return 0;
}