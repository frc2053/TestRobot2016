#include "vision.h"


VisionClass::VisionClass() {

}

/**
 * @param angle a nonnormalized angle
 */
 double VisionClass::normalize360(double angle){
	while(angle >= 360.0)
	{
		angle -= 360.0;
	}
	while(angle < 0.0)
	{
		angle += 360.0;
	}
	return angle;
}



 /**
  *
  * reads an image from a live image capture and outputs information to the SmartDashboard or a file
  */
 void VisionClass::processImage()
 {
	 while(1) {
		 printf("before image read!\n");
		 videoCapture.read(matOriginal);
		 printf("after image read!\n");
		 std::cout << "Width: " << matOriginal.cols << std::endl;
		 std::cout << "Height: " << matOriginal.rows << std::endl;
	 }
 }

/**
 *
 * @param args command line arguments
 * just the main loop for the program and the entry points
 */
void VisionClass::visionTest() {
	// TODO Auto-generated method stub
	printf("1\n");
	matOriginal =  cv::Mat();
	printf("2\n");
	matHSV =  cv::Mat();
	matThresh =  cv::Mat();
	clusters =  cv::Mat();
	matHeirarchy =  cv::Mat();
	rgb = cv::Mat();
	matResize = cv::Mat();
	testingMat = cv::Mat();
	printf("before open!\n");
	videoCapture.open(1);
	printf("after open!\n");
	while(!videoCapture.isOpened()){
		printf("videoCapture could not open!\n");
	}

//  main loop of the program
	processImage();
    cv::imwrite("/home/lvuser/output.jpg", matOriginal);
    cv::imwrite("/home/lvuser/outputrgb.jpg", rgb);
    videoCapture.release();
}

int VisionClass::getTargetX() {
	return center.x;
}

int VisionClass::getTargetY() {
	return center.y;
}

float VisionClass::getDistanceY() {
	return distance;
}

int VisionClass::getDistanceToCenter() {
	return abs(centerOfCam.x - center.x);
}

