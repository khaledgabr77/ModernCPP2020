#include <iostream>
#include <string>

struct NameInt {
  int num;
  std::string name;
};
void PrintStruct(const NameInt &s) {
  std::cout << s.name << " " << s.num << std::endl;
}

int main() {
  NameInt var{1, std::string{"hello"}};
  PrintStruct(var);
  PrintStruct({10, std::string{"khaled"}});
  return 0;
}