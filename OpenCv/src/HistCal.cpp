#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/base.hpp>
#include <opencv2/core/fast_math.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

int main() {
  std::string path = "../src/light.jpg";
  cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
  cv::Mat res;
  cv::resize(image, res, cv::Size(800, 800));
  if (image.empty()) {
    std::cerr << "Could not find image: " << std::endl;
    return 1;
  }
  std::vector<cv::Mat> bgr_planes;
  cv::split(res, bgr_planes);
  int histSize = 256;
  float range[] = {0, 256};
  const float *histRange = {range};
  bool uniform = true, accumulate = false;

  cv::Mat b_hist, g_hist, r_hist;
  cv::calcHist(&bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize,
               &histRange, uniform, accumulate);
  cv::calcHist(&bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize,
               &histRange, uniform, accumulate);
  cv::calcHist(&bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize,
               &histRange, uniform, accumulate);

  int hist_w = 512, hist_h = 400;
  int bin_w = cvRound((double)hist_w / histSize);
  cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));
  cv::normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1,
                cv::Mat());
  cv::normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1,
                cv::Mat());
  cv::normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1,
                cv::Mat());

  for (int i = 0; i < histSize; i++) {
    cv::line(
        histImage,
        cv::Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
        cv::Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
        cv::Scalar(255, 0, 0), 2, 8, 0);

    cv::line(
        histImage,
        cv::Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
        cv::Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
        cv::Scalar(0, 0, 255), 2, 8, 0);

    cv::line(
        histImage,
        cv::Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
        cv::Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
        cv::Scalar(0, 255, 0), 2, 8, 0);
  }
  cv::imshow("cal", histImage);
  cv::waitKey(0);
}