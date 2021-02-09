#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>

int main() {
  std::string a;
  std::string b;
  std::cin >> a >> b;
  std::cout << a.size() << std::endl;
  std::cout << b.size() << std::endl;
  std::cout << a + b << std::endl;
  std::swap(a[0], b[0]);
  std::cout << a << " " << b << std::endl;
}