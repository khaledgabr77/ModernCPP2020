#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

int main() {
  cv::VideoCapture cap("/home/khaled/Downloads/WhatsApp.mp4");
  if (cap.isOpened() == false) {
    std::cerr << "Cannot ope the video file" << std::endl;
    return 1;
  }
  double fps = cap.get(cv::CAP_PROP_FPS);
  std::string window_name = "My First Video";
  cv::namedWindow(window_name, cv::WINDOW_NORMAL);
  while (true) {
    cv::Mat frame;
    bool bSuccess = cap.read(frame);
    if (bSuccess == false) {
      std::cout << "Found the end of video " << std::endl;
      break;
    }
    cv::imshow(window_name, frame);
    if (cv::waitKey(10) == 27) {
      std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
      break;
    }
  }
}