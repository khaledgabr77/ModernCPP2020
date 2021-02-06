#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::map<int, std::string> khaled;
  khaled.emplace(1600, "kek");
  khaled.emplace(1500, "Lolo");
  khaled.emplace(1400, "Teeo");

  for (const auto &[id, name] : khaled) {
    std::cout << "Id: " << id << ", " << name << std::endl;
  }
  return 0;
}