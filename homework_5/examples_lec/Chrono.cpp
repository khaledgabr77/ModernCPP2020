#include <chrono>
#include <iostream>

long fiboncci(unsigned n) {
  if (n < 2)
    return n;
  return fiboncci(n - 1) + fiboncci(n - 2);
}

int main() {
  auto start = std::chrono::steady_clock::now();
  std::cout << "f(42) = " << fiboncci(200) << "\n";
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapse_second = end - start;
  std::cout << "elapse time: " << elapse_second.count() << "s\n";
}