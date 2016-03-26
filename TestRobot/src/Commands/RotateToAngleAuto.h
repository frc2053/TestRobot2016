#ifndef RotateToAngleAuto_H
#define RotateToAngleAuto_H

#include "Commands/CommandGroup.h"
#include "../Robot.h"

class RotateToAngleAuto: public CommandGroup
{
public:
	RotateToAngleAuto(float offset);
};

#endif
