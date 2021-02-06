#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{3, 50, 100, 10, 9};

  auto print = [](const int &n) { std::cout << " " << n << std::endl; };
  std::for_each(v.cbegin(), v.cend(), print);
}