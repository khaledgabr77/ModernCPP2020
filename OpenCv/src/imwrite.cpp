#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat image = cv::imread("light2.png", cv::IMREAD_GRAYSCALE);
  cv::imwrite("khaled.png", image);
  return 0;
}