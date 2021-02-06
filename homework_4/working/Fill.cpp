#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {0, 1, 2, 3, 4, 5};
  std::fill(v.begin(), v.end(), -1);
  for (const auto &kk : v) {
    std::cout << kk << std::endl;
  }
}