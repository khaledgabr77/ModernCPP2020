#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>

const int max_value_H = 360 / 2;
const int max_value = 255;
int main() {

  std::string path1 = "../src/light.jpg";

  cv::Mat image1 = cv::imread(path1, cv::IMREAD_COLOR);
  cv::Mat res;
  cv::resize(image1, res, {500, 500});

  if (image1.empty()) {
    std::cerr << "Could not find image: " << std::endl;
    return 1;
  }
  std::vector<int> lower_bound = {170, 80, 50};

  int low_H = lower_bound[0], low_S = lower_bound[1], low_V = lower_bound[2];
  int high_H = max_value_H, high_S = max_value, high_V = max_value;

  cv::Mat hsvImg, imgThreshold;
  cv::cvtColor(image1, hsvImg, cv::COLOR_BGR2HSV);
  cv::inRange(hsvImg, cv::Scalar(low_H, low_S, low_V),
              cv::Scalar(high_H, high_S, high_V), imgThreshold);

  // cv::Mat dst;
  // cv::medianBlur(image1, dst, 5);

  // cv::Mat dst2;
  // cv::GaussianBlur(image1, dst2, cv::Size(1, 1), 9, 9);

  // cv::imshow("gary", gray);
  // cv::imshow("Original", image1);
  // cv::imshow("median", dst);
  // cv::imshow("gaussian", dst2);
  cv::imshow("Threshold Image", imgThreshold);
  cv::imshow("HSV", hsvImg);

  int k = cv::waitKey(0); // Wait for a keystroke in the window

  if (k == 'q') {
    cv::destroyAllWindows();
  }
  return 0;
}