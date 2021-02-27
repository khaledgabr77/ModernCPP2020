#pragma once
#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

std::vector<cv::Point2f> pointsPlate;
std::vector<cv::Point2f> destinationPlate;
std::vector<cv::Point2f> pointsSnooker;
std::vector<cv::Point2f> destinationSnooker;

void platePoints(int event, int x, int y, int flags, void *userdata) {
  if (event == cv::EVENT_LBUTTONDOWN and pointsPlate.size() < 3) {
    std::cout << "Plate - position (" << x << ", " << y << " )" << std::endl;
    pointsPlate.push_back(cv::Point2f(x, y));
  } else if (event == cv::EVENT_LBUTTONDOWN) {
    std::cout << "Plate - destination(" << x << "," << y << ")" << std::endl;
    destinationPlate.push_back(cv::Point2f(x, y));
  }
}
void snookerPoints(int event, int x, int y, int flags, void *userdata) {
  if (event == cv::EVENT_LBUTTONDOWN and pointsSnooker.size() < 4) {
    std::cout << "Snooker - Position(" << x << ", " << y << ")" << std::endl;

    pointsSnooker.push_back(cv::Point2f(x, y));
  }

  else if (event == cv::EVENT_LBUTTONDOWN) {
    std::cout << "Snooker - destination (" << x << ", " << y << std::endl;
    destinationSnooker.push_back(cv::Point2f(x, y));
  }
}