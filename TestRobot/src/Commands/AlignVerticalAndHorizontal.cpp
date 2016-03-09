#include "AlignVerticalAndHorizontal.h"
#include "GoalAlign.h"
#include "GoalAlignVertical.h"
#include "DriveCommandAuto.h"

AlignVerticalAndHorizontal::AlignVerticalAndHorizontal(float angle)
{
	AddSequential(new GoalAlign(angle));
	AddSequential(new GoalAlignVertical(96));
	//AddSequential(new DriveCommandAuto(0,0,0,.5,0));
}
