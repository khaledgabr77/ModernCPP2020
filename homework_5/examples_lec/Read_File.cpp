#include <fstream> // For the file streams .
#include <ios>
#include <iostream>
#include <string>
using namespace std; // Saving space .
int main() {

  std::string l;
  std::ifstream kk("test.cols.txt", std::ios_base::in);
  while (kk >> l) {
    cout << l << endl;
  }
  return 0;
}
