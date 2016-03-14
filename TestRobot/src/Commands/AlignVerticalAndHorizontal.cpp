#include "AlignVerticalAndHorizontal.h"
#include "GoalAlign.h"
#include "GoalAlignVertical.h"
#include "DriveCommandAuto.h"

AlignVerticalAndHorizontal::AlignVerticalAndHorizontal(float angle)
{
	AddSequential(new GoalAlignVertical(101));
	AddSequential(new GoalAlign(angle));
	//AddSequential(new DriveCommandAuto(0,0,0,.5,0));

}
