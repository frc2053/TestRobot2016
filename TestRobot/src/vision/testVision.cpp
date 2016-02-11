#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
void testVision() {
    cv::VideoCapture vcap;
    cv::Mat image;

    const int videoStreamAddress = 0;
       //open the video stream and make sure it's opened
    if(!vcap.open(videoStreamAddress)) {
        std::cout << "Error opening video stream or file" << std::endl;
    }

    while(1) {
        if(!vcap.read(image)) {
            std::cout << "No frame" << std::endl;
            cv::waitKey();
        }
        cv::imshow("Output Window", image);

        if(cv::waitKey(1) >= 0) break;
    }

}
