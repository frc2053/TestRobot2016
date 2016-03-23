/*
 * DummyPIDOutput.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: TigerTronics
 */

#include "DummyPIDOutput.h"

DummyPIDOutput::DummyPIDOutput() {
	output = 0;
}

DummyPIDOutput::~DummyPIDOutput() {

}

void DummyPIDOutput::PIDWrite(double _output) {
	output = _output;
}

double DummyPIDOutput::GetOutput() {
	return output;
}

