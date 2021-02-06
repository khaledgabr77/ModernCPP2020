#include <algorithm>
#include <array>
#include <iostream>

int main() {

  std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
  for (const auto &arr : s) {
    std::cout << "Before Sorting: " << arr << std::endl;
  }
  std::sort(s.begin(), s.end());
  for (const auto &x : s) {
    std::cout << "After Sorting: " << x << std::endl;
  }
}