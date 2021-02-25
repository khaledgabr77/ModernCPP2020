#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>

int main() {
  std::string path = "../src/khaled.jpg";
  cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
  cv::Mat res;
  cv::resize(image, res, {300, 300});
  if (image.empty()) {
    std::cout << "Could not find image: " << std::endl;
    return 0;
  }
  cv::Mat blu;
  cv::Mat med;
  cv::Mat gau;
  cv::Mat bitl;

  cv::blur(res, blu, cv::Size(5, 5));
  cv::medianBlur(res, med, 5);
  cv::GaussianBlur(res, gau, cv::Size(1, 1), 5, 6);
  cv::bilateralFilter(res, bitl, 5, 6, 7);
  cv::imshow("original", res);
  cv::imshow("blur", blu);
  cv::imshow("median", med);
  cv::imshow("gaussian", gau);
  cv::imshow("bilateralfilter", bitl);
  cv::waitKey(0);
}
