#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
  // program should take 2 command arg
  std::cout << "number of arg are: " << argc << std::endl;
  if ((argc - 1) != 2) {
    std::cerr << "only 2 inputs arg allowed..Aborting the program";
    exit(EXIT_FAILURE);
  } else {
    std::string filename1, filename2;
    filename1 = argv[1];
    filename2 = argv[2];

    std::stringstream filename1s{filename1};
    std::stringstream filename2s{filename2};
    int n1, n2 = -1;
    std::string s1, s2;

    filename1s >> n1 >> s1;
    filename2s >> n2 >> s2;

    std::cout << n1 << " " << n2 << std::endl;
    std::cout << s1 << " " << s2 << std::endl;
  }
}