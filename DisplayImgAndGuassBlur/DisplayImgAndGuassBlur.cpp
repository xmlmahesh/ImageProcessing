#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int DisplayImage(string filePath);
int GuassianBlurEffect(string filePath);

int main(int argc, char** argv)
{

	DisplayImage(argv[1]);
	//GuassianBlurEffect(argv[1]);
	
	return 0;
}

int DisplayImage(string filePath)
{
	Mat image;
	image = imread(filePath, IMREAD_COLOR); // Read the file

	if (image.empty())
		return -1;

	namedWindow("DisplayImage", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("DisplayImage", image); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	destroyWindow("DisplayImage");

	return 0;
}

int GuassianBlurEffect(string filePath)
{
	cv::Mat image;
	image = imread(filePath, IMREAD_COLOR);

	if (image.empty())
		return -1;

	cv::namedWindow("blurrIn", cv::WINDOW_FULLSCREEN);
	cv::namedWindow("blurrOut", cv::WINDOW_FULLSCREEN);

	cv::imshow("blurrIn", image);

	Mat iOut;

	cv::GaussianBlur(image, iOut, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(iOut, iOut, Size(5, 5), 3, 3);

	imshow("blurrOut", iOut);
	waitKey(0);
	return 0;
}