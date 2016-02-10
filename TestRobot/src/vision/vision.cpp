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
 void VisionClass::processImage(){

	//buttonPressed = Robot::oi->getDriveJoystick()->GetRawButton(5);
	printf("IM AM IN PROCESS IMAGE!\n");
 	double x,y,targetX,targetY,azimuth;
 	//int FrameCount = 0;
 	while(true) {
 		videoCapture.read(matOriginal);
 		if(matOriginal.empty()) {
 			break;
 		}
 		 		//std::cout << "frameCount: " << FrameCount << std::endl;
 		 		contours.clear();
 		 		selected.clear();
 		 //			capture from the axis camera
 		 		//printf("before read\n");
 		 		//printf("after read\n");
 		 //			captures from a static file for testing
 		 		//matOriginal = cv::imread("/home/lvuser/original.png");
 		 		//cv::imwrite("/home/lvuser/original.jpg", matOriginal);
 		 		cv::resize(matOriginal, matResize, resize);
 		 		matOriginal.copyTo(testingMat);
 		 		cv::cvtColor(matResize,matHSV,cv::COLOR_BGR2HSV);
 		 		cv::inRange(matHSV, LOWER_BOUNDS, UPPER_BOUNDS, matThresh);
 		 		cv::findContours(matThresh, contours, matHeirarchy, cv::RETR_EXTERNAL,
 		 				cv::CHAIN_APPROX_SIMPLE);
 		 		//std::cout << "Size of contours: " << contours.size() << std::endl;
 		 //			make sure the contours that are detected are at least 20x20
 		 //			pixels with an area of 400 and an aspect ration greater then 1
 		 		//printf("looping\n");
 		 		for (unsigned int i = 0; i < contours.size();  i++) {
 		 			cv::Rect rec = cv::boundingRect(contours[i]);
 					float aspect = (float)rec.width/(float)rec.height;
 					if(aspect > 1.0) {
 						if(rec.area() > biggestArea)
 							biggestArea = rec.area();
 							selected.push_back(contours[i]);
 						}
 		 		}
 		 		//std::cout << "Size of selected: " << selected.size() << std::endl;
 		 		for(unsigned int i = 0; i < selected.size(); i++){
 		 			cv::Rect rec = cv::boundingRect(selected[i]);
 		 			//std::cout << "looping on selected!" << std::endl;
 		 			cv::rectangle(matResize, rec.br(), rec.tl(), BLACK);
 		 		}
 		 //			if there is only 1 target, then we have found the target we want
 		 		if(selected.size() == 1){
 		 			//std::cout << "selected is one!" << std::endl;
 		 			cv::Rect rec = cv::boundingRect(selected[0]);
 		 //				"fun" math brought to you by miss daisy (team 341)!
 		 			y = rec.br().y + rec.height / 2;
 		 			y= -((2 * (y / matResize.cols)) - 1);
 		 			visionMutex.lock();
 		 			distance = (TOP_TARGET_HEIGHT - TOP_CAMERA_HEIGHT) /
 		 					tan((y * VERTICAL_FOV / 2.0 + CAMERA_ANGLE) * PI / 180);
 		 //				angle to target...would not rely on this
 		 			targetX = rec.tl().x + rec.width / 2;
 		 			targetX = (2 * (targetX / matResize.rows)) - 1;
 		 			azimuth = normalize360(targetX*HORIZONTAL_FOV /2.0 + 0);
 		 //				drawing info on target
 		 			center =  cv::Point(rec.br().x-rec.width / 2 - 15,rec.br().y - rec.height / 2);
 		 			cv::Point centerw =  cv::Point(rec.br().x-rec.width / 2 - 15,rec.br().y - rec.height / 2 - 20);
 		 			int distanceX = center.x;
 		 			int distanceY = center.y;
 		 			cv::putText(matResize, std::to_string(distanceX), center, cv::FONT_HERSHEY_PLAIN, 1, GREEN);
 		 			cv::putText(matResize, std::to_string(distanceY), centerw, cv::FONT_HERSHEY_PLAIN, 1, GREEN);
 		 			std::cout << "Center: " << center << std::endl;
 		 			std::cout << "Distance: " << distance << std::endl;
 		 			visionMutex.unlock();
 		 		}
 		 		/*if(Robot::oi->getdriverJoystick()->GetRawButton(6)) {
 		 			std::stringstream ss;
 		 			ss << "/home/lvuser/testing" << pictureTaker << ".jpg";
 		 			std::string s = ss.str();
 		 			cv::imwrite(s, matResize);
 		 		}*/
 		 		pictureTaker++;
 		 //			output an image for debugging
 		 		//cv::imwrite("/var/volatile/tmp/opencv-frame.jpg", matOriginal);
 		 		//image = frcCreateImage(IMAQ_IMAGE_RGB);
 		 		//frcReadImage(image, "/var/volatile/tmp/opencv-frame.jpg");
 		 		cvtColor(matResize, rgb, cv::COLOR_BGR2RGB, 0);
 		 		imaqArrayToImage(myImaqImage, matResize.data, matResize.cols, matResize.rows);
 		 		CameraServer::GetInstance()->SetImage(myImaqImage);
 		 		//FrameCount++;
 		 	//shouldRun = false;
 			}
 		}

/**
 *
 * @param args command line arguments
 * just the main loop for the program and the entry points
 */
void VisionClass::visionTest() {
	// TODO Auto-generated method stub
	matOriginal =  cv::Mat();
	matHSV =  cv::Mat();
	matThresh =  cv::Mat();
	clusters =  cv::Mat();
	matHeirarchy =  cv::Mat();
	rgb = cv::Mat();
	matResize = cv::Mat();
	testingMat = cv::Mat();
	myImaqImage = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	videoCapture =  cv::VideoCapture();
	videoCapture.open(0);
//		main loop of the program
	while(shouldRun){
		while(!videoCapture.isOpened()){
			printf("videoCapture could not open!\n");
		}
//			time to actually process the acquired images
		processImage();
	 	cv::imwrite("/home/lvuser/output.jpg", matOriginal);
	 	cv::imwrite("/home/lvuser/outputrgb.jpg", rgb);
	}
//		make sure the java process quits when the loop finishes
	videoCapture.release();
	exit(0);
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

