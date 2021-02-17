#include <iostream>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat image(600, 800, CV_8UC3, cv::Scalar(100, 250, 30));
  std::string windowName = "window with Blank Image";
  cv::namedWindow(windowName);
  cv::imshow(windowName, image);
  cv::waitKey(0);
  cv::destroyWindow(windowName);
  return 0;
}