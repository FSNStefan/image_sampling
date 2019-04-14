// ImageSampling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	int sampling = 0;
	cout << "Please input an integer:" << endl;
	cin >> sampling;
	if (argc != 2) {
		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}
	Mat image;
	int currentI = 0, currentJ = 0, count = 1, x = 0, y = 0;
	image = imread("home.jpg", CV_LOAD_IMAGE_COLOR);
	//image = imread(argv[1], CV_LOAD_IMAGE_COLOR); // Read the file
	if (!image.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	Vec3b intensity;
	while (count < image.rows || count < image.cols) {
		intensity = image.at<Vec3b>(currentI, currentJ);
		for (int i = currentI; i < currentI + sampling; i++) {
			x = i;
			for (int j = currentJ; j < currentJ + sampling; j++) {
				y = j;
				image.at<Vec3b>(x, y) = intensity;
			}
		}
		count += sampling;
		currentI = count; currentJ = count;
	}
    return 0;
}

