/*
 * DummyPIDSource.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: TigerTronics
 */

#include "DummyPIDSource.h"

DummyPIDSource::DummyPIDSource() {
	input = 0;
}

DummyPIDSource::~DummyPIDSource() {

}

double DummyPIDSource::pidGet() {
	return input;
}

void DummyPIDSource::PIDWrite(double _input) {
	input = _input;
}

