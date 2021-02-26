#include <iostream>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

int main() {
  std::vector<cv::String> fileNames;
  cv::glob("path", fileNames, false);
  cv::Size patternSize(25 - 1, 18 - 1);
  std::vector<std::vector<cv::Point2f>> q(fileNames.size());
  std::vector<std::vector<cv::Point3f>> Q;
}