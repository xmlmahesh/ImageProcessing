
#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void AnnotateImage(Mat image, string text);
void DrawCircleOnImage(Mat image);

int main(int argc, char** argv)
{
	//create blank image
	Mat blank_image = Mat::zeros(500, 500, CV_8UC3);

	DrawCircleOnImage(blank_image);
	//AnnotateImage(blank_image, "Hello Image");

	return 1;
}

/*
Simple text annotate on image
*/
void AnnotateImage(Mat image, string text)
{
	namedWindow("DisplayImage", WINDOW_AUTOSIZE); // Create a window for display.

	putText(image, text, Point(0, 100), FONT_HERSHEY_PLAIN, 5, Scalar(255, 0, 0), 2, 8);

	imshow("DisplayImage", image); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	destroyWindow("DisplayImage");

}

/*
Simple drawing on image
*/
void DrawCircleOnImage(Mat image)
{
	namedWindow("DisplayImage", WINDOW_AUTOSIZE); // Create a window for display.

	circle(image, Point(250, 250), 25, Scalar(0, 0, 255), 2, 8);

	imshow("DisplayImage", image); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	destroyWindow("DisplayImage");

}