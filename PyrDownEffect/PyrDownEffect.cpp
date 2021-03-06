#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int PyrDownEffect(string filePath);

int main(int argc, char** argv)
{
	PyrDownEffect(argv[1]);

	return 0;
}


int PyrDownEffect(string filePath)
{
	Mat img1, img2;

	namedWindow("imageIn", WINDOW_AUTOSIZE);
	namedWindow("imageOut", WINDOW_AUTOSIZE);
	
	
	img1 = imread(filePath);

	if (img1.empty())
		return -1;
	

	imshow("imageIn", img1);
	pyrDown(img1, img2);
	imshow("imageOut", img2);

	waitKey(0);
	return 0;
}

