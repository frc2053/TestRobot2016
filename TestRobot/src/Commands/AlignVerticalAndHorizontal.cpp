#include "AlignVerticalAndHorizontal.h"
#include "GoalAlign.h"
#include "GoalAlignVertical.h"

AlignVerticalAndHorizontal::AlignVerticalAndHorizontal()
{
	AddSequential(new GoalAlignVertical(120));
	AddSequential(new GoalAlign());
}
