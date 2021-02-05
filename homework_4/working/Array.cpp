#include <array>
#include <iostream>

int main() {
  std::array<float, 10> khaled{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (const auto &elem : khaled) {
    std::cout << elem << std::endl;
    std::cout << khaled[1] << std::endl;
  }
  std::cout << "array size: " << khaled.size() << std::endl;
  std::cout << "array empty: " << khaled.empty() << std::endl;
  std::cout << "first element: " << khaled.front() << std::endl;
  std::cout << "last element: " << khaled.back() << std::endl;
}