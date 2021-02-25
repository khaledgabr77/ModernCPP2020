#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>

int main() {
  std::string path = "../src/hist.jpg";
  cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
  if (image.empty()) {
    std::cerr << "Could not find image: " << std::endl;
    return 1;
  }
  cv::Mat res;
  cv::resize(image, res, cv::Size(800, 800));
  cv::Mat gray;
  cv::cvtColor(res, gray, cv::COLOR_BGR2GRAY);
  cv::Mat equ;
  cv::equalizeHist(gray, equ);
  cv::imshow("equ", equ);
  cv::waitKey(0);
  return 0;
}