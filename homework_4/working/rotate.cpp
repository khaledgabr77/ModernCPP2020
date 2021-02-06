#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "Before Rotating: " << std::endl;
  for (auto kk : v) {
    std::cout << kk << std::endl;
  }
  std::rotate(v.begin(), v.begin() + 3, v.end());
  for (auto ll : v) {
    std::cout << "After Rotat: " << ll << std::endl;
  }
}