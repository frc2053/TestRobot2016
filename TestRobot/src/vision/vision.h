/*
 * vision.h
 *
 *  Created on: Jan 15, 2016
 *      Author: tigertronics
 */

#ifndef SRC_VISION_VISION_H_
#define SRC_VISION_VISION_H_

#define PI 3.14159265

#include <opencv2/opencv.hpp>
#include <cmath>
#include <ctime>
#include "WPILib.h"

class VisionClass {
public:
	VisionClass();
	void visionTest();
	void processImage();
	double normalize360(double angle);
	int getTargetX();
	int getTargetY();
	int getDistanceToCenter();
	float getDistanceY();
	VisionClass* visionClass;
private:
	std::mutex visionMutex;
//	constants for the color rbg values
	const cv::Scalar RED = cv::Scalar(0, 0, 255),
	BLUE = cv::Scalar(255, 0, 0),
	GREEN = cv::Scalar(0, 255, 0),
	BLACK = cv::Scalar(0,0,0),
	YELLOW = cv::Scalar(0, 255, 255),
//	these are the threshold values in order
	LOWER_BOUNDS = cv::Scalar(0,200,0),
	UPPER_BOUNDS = cv::Scalar(50,255,50);
	//rgb bgr
	//lower: 0,177,25 - 25,177,0
	//upper: 148,255,255 - 255,255,148

	double distance = 0;


//	the size for resing the image
	const cv::Size resize = cv::Size(320,240);
	const cv::Point centerOfCam = cv::Point(160, 120);
	cv::Point center;

//	ignore these
	 cv::VideoCapture videoCapture;
	 cv::Mat matOriginal, matHSV, matThresh, clusters, matHeirarchy, matGray, matResize, testingMat;
	 Image* myImaqImage;

//	Constants for known variables
//	the height to the top of the target in first stronghold is 97 inches
	 const int TOP_TARGET_HEIGHT = 97;
//	the physical height of the camera lens
	 const int TOP_CAMERA_HEIGHT = 26;

//	camera details, can usually be found on the datasheets of the camera
	 const double VERTICAL_FOV  = 42;
	 const double HORIZONTAL_FOV  = 56;
	 const double CAMERA_ANGLE = 10;

	 bool shouldRun = true;

	 int biggestArea = 0;
	 int biggestAreaIndex = 0;

	 bool buttonPressed = false;

	 std::vector<std::vector<cv::Point>> contours;
	 std::vector<std::vector<cv::Point>> selected;

	 int pictureTaker = 0;
};





#endif /* SRC_VISION_VISION_H_ */
