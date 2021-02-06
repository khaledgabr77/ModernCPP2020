#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<int> num = {1, 2, 3};
  std::vector<std::string> names = {"khaled", "mahomud}"};

  names.emplace_back("Gabr"); //==push_back

  std::cout << "first name: " << names.front() << std::endl;
  std::cout << "last num: " << num.back() << std::endl;
  std::cout << "first name: " << names.back() << std::endl;
}