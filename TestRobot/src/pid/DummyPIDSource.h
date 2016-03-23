/*
 * DummyPIDSource.h
 *
 *  Created on: Mar 23, 2016
 *      Author: TigerTronics
 */

#ifndef SRC_PID_DUMMYPIDSOURCE_H_
#define SRC_PID_DUMMYPIDSOURCE_H_

#include "WPILib.h"

class DummyPIDSource : public PIDSource {
public:
	DummyPIDSource();
	virtual ~DummyPIDSource();
	double pidGet();
	void PIDWrite(double input);
private:
	double input;
};

#endif /* SRC_PID_DUMMYPIDSOURCE_H_ */
