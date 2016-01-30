/*
 * vision.h
 *
 *  Created on: Jan 15, 2016
 *      Author: tigertronics
 */

#ifndef SRC_VISION_VISION_H_
#define SRC_VISION_VISION_H_

#include "../Robot.h"

void visionTest();
void processImage();
double normalize360(double angle);
int getTargetX();
int getDistance();



#endif /* SRC_VISION_VISION_H_ */
