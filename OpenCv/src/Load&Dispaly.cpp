#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat image = cv::imread("../src/light2.png", cv::IMREAD_GRAYSCALE);

  if (image.empty()) {
    std::cerr << "Could not find iamge or path" << std::endl;
    return 1;
  }
  cv::imshow("kahled", image);
  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}