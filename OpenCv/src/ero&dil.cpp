#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>

int main() {
  std::string path = "../src/light.jpg";
  cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
  if (image.empty()) {
    std::cerr << "Image not Found: " << std::endl;
    return 1;
  }
  cv::Mat res;
  cv::Mat ero;
  cv::Mat eli;
  cv::resize(image, res, {800, 800});
  cv::erode(res, ero, cv::Mat(), cv::Point(-1, -1), 3);
  cv::dilate(res, eli, cv::Mat(), cv::Point(-1, -1), 3);
  cv::imshow("ero", ero);
  cv::imshow("eli", eli);
  int k = cv::waitKey(0); // Wait for a keystroke in the window

  if (k == 'q') {
    cv::destroyAllWindows();
  }
  return 0;
}