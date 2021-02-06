#include <algorithm>
#include <iostream>
#include <vector>

inline bool div_by_3(int i) { return i % 3 == 0; }

int main() {
  std::vector<int> v{1, 2, 3, 3, 5, 6, 7, 9};
  int n3 = std::count_if(v.begin(), v.end(), div_by_3);
  std::cout << " divisible by 3: " << n3 << std::endl;
}