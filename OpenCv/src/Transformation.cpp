#include "mouse.h"
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat snookerImg = cv::imread("../src/snooker.jpg");
  cv::Mat plateImg = cv::imread("../src/palet.jpg");

  cv::Mat perspecImg, affineImg;
  if (snookerImg.empty() || plateImg.empty()) {
    std::cerr << "Error, Loading the imgae: " << std::endl;
    return 1;
  }
  cv::namedWindow("Original Plate", 1);
  cv::namedWindow("Original snooker", 1);

  cv::setMouseCallback("Original Plate", platePoints, NULL);
  cv::setMouseCallback("Original snooker", snookerPoints, NULL);

  cv::imshow("original plate", plateImg);
  cv::imshow("original snooker", snookerImg);
  cv::waitKey(0);

  std::cout << "Points plate: " << std::endl;
  for (auto &i : pointsPlate) {
    std::cout << "(" << i.x << ", " << i.y << ")" << std::endl;
  }
  std::cout << "Destination Plate: " << std::endl;
  for (auto &i : destinationPlate) {
    std::cout << "(" << i.x << "," << i.y << ")" << std::endl;
  }
  cv::Mat affinematrix = cv::getAffineTransform(pointsPlate, destinationPlate);
  cv::warpAffine(plateImg, affineImg, affinematrix, plateImg.size());

  cv::imshow("Plate Transformation", affineImg);

  cv::Mat perspectiveMatrix =
      cv::getPerspectiveTransform(pointsSnooker, destinationSnooker);
  cv::warpPerspective(snookerImg, perspecImg, perspectiveMatrix,
                      snookerImg.size());
  cv::imshow("Perspective Transformation", perspecImg);

  // Wait until user press some key
  cv::waitKey(0);

  return 0;
}