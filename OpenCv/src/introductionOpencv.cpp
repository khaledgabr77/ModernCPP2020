#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>

int main() {

  std::string image_path1 = "../src/light.jpg";
  std::string image_path2 = "../src/khaled.jpg";

  cv::Mat astro1 = cv::imread(image_path1, cv::IMREAD_COLOR);
  cv::Mat astro2 = cv::imread(image_path2, cv::IMREAD_COLOR);

  if (astro1.empty() && astro2.empty()) {
    std::cerr << "Could not read the image: " << std::endl;
    return 1;
  }
  cv::Mat rotate1;
  cv::Mat rotate2;
  cv::rotate(astro1, rotate1, cv::ROTATE_90_COUNTERCLOCKWISE);
  cv::rotate(astro2, rotate2, cv::ROTATE_180);

  cv::Mat res1;
  cv::Mat res2;
  cv::resize(astro1, res1, cv::Size(300, 300));
  cv::resize(astro2, res2, cv::Size(300, 300));

  cv::Mat gray_image1;
  cv::Mat gray_image2;

  cv::cvtColor(astro1, gray_image1, cv::COLOR_BGR2GRAY);
  cv::cvtColor(astro2, gray_image2, cv::COLOR_BGR2GRAY);

  cv::imshow("d", astro1);
  cv::imshow("dd", astro2);
  cv::imshow("r", rotate1);
  cv::imshow("r", rotate2);
  cv::imshow("re", res1);
  cv::imshow("rr", res2);
  cv::imshow("g", gray_image1);
  cv::imshow("gg", gray_image2);

  cv::waitKey(0);
  return 0;
}