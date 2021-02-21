#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
  Mat image = imread("../src/light.jpg");

  cv::Mat gray;
  // Convert from Color Image to Gray image
  cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
  // Fixed Filter Size
  const int MEDIAN_BLUR_FILTER_SIZE = 7;
  // Use Median Filter to remover  and keep it sharp form iamge
  cv::medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE);

  // Matrix recive edge created from Laplacian filter
  cv::Mat edge;
  // Fixed the Size of filter
  const int LAPLACIAN_FILTER_SIZE = 5;
  // apply filter with gray image and saved in edge matrix
  cv::Laplacian(gray, edge, CV_8U, LAPLACIAN_FILTER_SIZE);
  imshow("labacian", edge);
  cv::Mat mask;
  const int EDGE_THRESHOLD = 50;
  cv::threshold(edge, mask, EDGE_THRESHOLD, 255, cv::THRESH_BINARY_INV);

  cv::Size size = image.size();
  cv::Size smallSize;
  smallSize.width = size.width / 2;
  smallSize.height = size.height / 2;
  cv::Mat smallImg = cv::Mat(smallSize, CV_8UC3);
  cv::resize(image, smallImg, smallSize, 0, 0, cv::INTER_LINEAR);

  cv::Mat tmp = cv::Mat(smallSize, CV_8UC3);
  int repetitions = 7; // Repetitions for strong cartoon effect.
  for (int i = 0; i < repetitions; i++) {
    int ksize = 9;
    // Filter size. Has a large effect on speed.
    double sigmaColor = 9;
    // Filter color strength.
    double sigmaSpace = 7;
    // Spatial strength. Affects speed.
    bilateralFilter(smallImg, tmp, ksize, sigmaColor, sigmaSpace);
    bilateralFilter(tmp, smallImg, ksize, sigmaColor, sigmaSpace);
  }
  cv::Mat display(image.size(), CV_8UC3);

  cv::Mat bigImg;
  resize(smallImg, bigImg, size, 0, 0, cv::INTER_LINEAR);
  display.setTo(0);
  bigImg.copyTo(display, mask);

  cv::Mat edge2;
  cv::Scharr(image, edge2, CV_8U, 1, 0);
  cv::Scharr(image, edge, CV_8U, 1, 0, -1);
  edge += edge2;
  const int EVIL_EDGE_THRESHOLD = 12;
  cv::threshold(edge, mask, EVIL_EDGE_THRESHOLD, 255, cv::THRESH_BINARY_INV);
  cv::medianBlur(mask, mask, 3);

  imshow("light", mask);
  imshow("ll", edge2);
  imshow("Khaled", image);

  waitKey(0);
  return 0;
}