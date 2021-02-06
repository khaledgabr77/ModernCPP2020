#include <iostream>
#include <unordered_map>

int main() {

  std::unordered_map<int, std::string> khaled;
  khaled.emplace(9, "krkt");
  khaled.emplace(15, "khaled");
  khaled.emplace(10, "prpo");

  for (const auto &[id, name] : khaled) {
    std::cout << "Id: " << id << ", " << name << std::endl;
  }
  return 0;
}