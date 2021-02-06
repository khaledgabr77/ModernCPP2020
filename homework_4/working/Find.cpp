#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  const int n = 3;
  std::vector<int> v = {0, 1, 2, 3, 4};
  auto result = std::find(v.begin(), v.end(), n);
  if (result != v.end()) {

    std::cout << "we found it! : " << n << std::endl;
  } else {
    std::cout << "we didn't found it!!: " << n << std::endl;
  }
}