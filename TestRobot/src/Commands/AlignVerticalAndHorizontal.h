#ifndef AlignVerticalAndHorizontal_H
#define AlignVerticalAndHorizontal_H

#include "Commands/CommandGroup.h"
#include "../Robot.h"

class AlignVerticalAndHorizontal: public CommandGroup
{
public:
	AlignVerticalAndHorizontal(float angle);
};

#endif
