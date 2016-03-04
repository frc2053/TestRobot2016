#include "AlignVerticalAndHorizontal.h"
#include "GoalAlign.h"
#include "GoalAlignVertical.h"

AlignVerticalAndHorizontal::AlignVerticalAndHorizontal()
{
	AddSequential(new GoalAlignVertical(96));
	AddSequential(new GoalAlign());
}
