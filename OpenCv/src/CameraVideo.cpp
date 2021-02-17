#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

int main() {
  cv::VideoCapture cap(0);
  if (cap.isOpened() == false) {
    std::cerr << "Cann't open Video camera" << std::endl;
    return 1;
  }
  double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
  double dHeight = cap.get(cv::CAP_PROP_FRAME_WIDTH);
  std::cout << "Resolution of Video: " << dWidth << "x" << dHeight << std::endl;
  std::string window_name = "My Camera Feed";
  cv::namedWindow(window_name);
  while (true) {
    cv::Mat frame;
    bool bScuccess = cap.read(frame);
    if (bScuccess == false) {
      std::cerr << "Video is disconnected" << std::endl;
      break;
    }
    cv::imshow(window_name, frame);
    if (cv::waitKey(10) == 27) {
      std::cout << "Esc key is pressed by user. Stooping the video"
                << std::endl;
      break;
    }
  }
  return 0;
}