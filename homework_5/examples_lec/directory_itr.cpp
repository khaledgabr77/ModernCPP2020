#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;
int main() {
  fs::create_directories("sandbox/a/b");
  std::ofstream("sandbox/file1.txt");
  std::ofstream("sandbox/file2.txt");
  for (auto &p : fs::directory_iterator("sandbox")) {
    std::cout << p.path() << "\n";
  }
  // if you need to remove folder that created
  // fs::remove_all("sandbox");
}