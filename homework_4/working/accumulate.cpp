#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int sum = std::accumulate(v.begin(), v.end(), 0);
  int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Product: " << product << std::endl;
}