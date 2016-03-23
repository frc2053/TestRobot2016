/*
 * DummyPIDOutput.h
 *
 *  Created on: Mar 23, 2016
 *      Author: TigerTronics
 */

#ifndef SRC_PID_DUMMYPIDOUTPUT_H_
#define SRC_PID_DUMMYPIDOUTPUT_H_

#include "WPILib.h"

class DummyPIDOutput : public PIDOutput {
public:
	DummyPIDOutput();
	virtual ~DummyPIDOutput();
	void PIDWrite(double output);
	double GetOutput();
private:
	double output;
};

#endif /* SRC_PID_DUMMYPIDOUTPUT_H_ */
