#include <iostream>
#include <type_traits>

int main() {
  int a = 3;
  int b = 5;
  std::cout << a << " " << b << "\n";
  std::swap(a, b);
  std::cout << a << " " << b << "\n";
  return 0;
}