#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  std::cout << fs::path("/foo/bar.txt").stem() << "\n"
            << fs::path("/foo/0000.png").stem() << '\n'
            << fs::path("foo/.bar").stem() << "\n";
}