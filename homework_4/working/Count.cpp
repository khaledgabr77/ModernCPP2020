#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 3, 6, 7, 8, 9};
  const int n1 = 3;
  const int n2 = 5;
  int num1 = std::count(v.begin(), v.end(), n1);
  int num2 = std::count(v.begin(), v.end(), n2);
  std::cout << n1 << "  Count  " << num1 << std::endl;
  std::cout << n2 << "  count  " << num2 << std::endl;

  return 0;
}
