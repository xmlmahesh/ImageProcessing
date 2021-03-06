#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int CannyEdgeDetector(string filePath);


int main(int argc, char** argv)
{
	CannyEdgeDetector(argv[1]);
	
	return 0;
}


int CannyEdgeDetector(string filePath)
{
	cv::Mat img_rgb, img_gry, img_cny;
	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);
	
	img_rgb = cv::imread(filePath);

	if (img_rgb.empty())
		return -1;

	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::imshow("Example Gray", img_gry);
	cv::Canny(img_gry, img_cny, 10, 100, 3, true);
	cv::imshow("Example Canny", img_cny);
	cv::waitKey(0);
	return 0;
}



