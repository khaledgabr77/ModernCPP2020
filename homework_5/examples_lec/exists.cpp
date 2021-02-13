#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void demo_exists(const fs::path &p) {
  std::cout << p;
  if (fs::exists(p))
    std::cout << "exists\n";
  else
    std::cout << "doesnot exist\n";
}

int main() {
  fs::create_directory("sandbox");
  std::ofstream("sandbox/file");
  demo_exists("sandbox/file");
  demo_exists("sanbox/khaled");
  fs::remove_all("sandbox");
}