#include <iostream>
#include <string>

void Print(const std::string &str) {
  std::cout << "Lvalue"
            << " " << str << std::endl;
}
void Print(std::string &&str) {
  std::cout << "Rvalue"
            << " " << str << std::endl;
}
int main() {
  std::string hello = "hi";
  Print(hello);
  Print("world");
  Print(std::move(hello));
}