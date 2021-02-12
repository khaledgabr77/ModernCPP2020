#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  std::cout << fs::path("/foo/bar.txt").filename() << std::endl
            << fs::path("/foo/.bar").filename() << std::endl
            << fs::path("/foo/bar/").filename() << std::endl
            << fs::path("/foo/.").filename() << std::endl
            << fs::path("/foo/..").filename() << std::endl;

  ;
}