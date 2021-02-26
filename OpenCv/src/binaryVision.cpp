#include <cstdlib>
#include <iostream>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

int main() {
  std::string path = "../src/light.jpg";
  cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
  cv::Mat res;
  cv::resize(image, res, cv::Size(600, 400));
  if (image.empty()) {
    std::cerr << "Could not find or show image: " << std::endl;
    return 1;
  }
  std::vector<std::vector<cv::Point>> contours;
  std::vector<cv::Vec4i> hierarchy;

  cv::Mat gray, binaryImg, contoursImg;
  cv::cvtColor(res, gray, cv::COLOR_RGB2GRAY);
  cv::threshold(gray, binaryImg, 50, 255, cv::THRESH_BINARY);

  cv::findContours(binaryImg, contours, hierarchy, cv::RETR_TREE,
                   cv::CHAIN_APPROX_NONE);

  for (int contour = 0; contour < contours.size(); contour++) {
    cv::Scalar colour(rand() & 0xFF, rand() & 0xFF, rand() & 0xFF);
    cv::drawContours(res, contours, contour, colour, cv::FILLED, 8, hierarchy);
  }
  // cv::imshow("resi", res);
  // cv::imshow("orignial", gray);

  cv::imshow("binary", binaryImg);
  cv::imshow("contour", res);
  cv::waitKey(0);
  return 0;
}