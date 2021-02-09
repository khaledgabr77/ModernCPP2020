#include <functional>
#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> StringFactor(bool create) {
  if (create) {
    std::cout << "Modern C++ is Awesome"
              << "\n";
  }
}
int main() {
  std::cout << StringFactor(true).value() << "\n";
  std::cout << StringFactor(false).value_or(":(") << "\n";
}