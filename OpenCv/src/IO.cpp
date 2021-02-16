#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <string>

int main() {
  using Matf = cv::Mat_<float>;
  Matf iamge = Matf::zeros(10, 10);
  iamge.at<float>(5, 5) = 42.42f;
  std::string f = "tets.exr";
  cv::imwrite(f, iamge);
  Matf copy = cv::imread(f, cv::IMREAD_UNCHANGED);
  std::cout << copy.at<float>(5, 5) << std::endl;
}