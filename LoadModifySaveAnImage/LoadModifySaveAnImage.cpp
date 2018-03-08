
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;


/*
Load modify save an Image
*/
int LoadModifySaveAnImage(string filePath)
{
	Mat img;
	img = imread(filePath, IMREAD_COLOR); // reading an image from the file path

	if (img.empty()) // check image loaded successfully
	{
		return -1;
	}

	/*now image has loaded into matrix img, lets do two type of functionality on the image
	a) Image scale down or reduce the file size
	b) Image convert from color to gray scale
	*/

	Mat gray_img;
	cvtColor(img, gray_img, COLOR_BGR2GRAY); //Image convert from color to gray scale

	replace(filePath.begin(), filePath.end(), '.', '_'); // replace char '.' with '_' so that we can output file with functionality names. 

	imwrite(filePath + "gray.jpg", gray_img);

	pyrDown(img, gray_img); //Image scale down or reduce the file size
	imwrite(filePath + "smallfile.jpg", gray_img);

	return 1;
}