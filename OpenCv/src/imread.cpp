#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

int main() {

  cv::Mat img1 = cv::imread("light2.png", cv::IMREAD_GRAYSCALE);
  cv::Mat_<uint8_t> img2 = cv::imread("light2.png", cv::IMREAD_GRAYSCALE);
  std::cout << (img1.type() == img2.type()) << std::endl;
  return 0;
}