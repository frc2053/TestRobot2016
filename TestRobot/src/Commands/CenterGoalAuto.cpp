#include "CenterGoalAuto.h"
#include "DriveCommandAuto.h"
#include "ShootHigh.h"
#include "DoNothing.h"
#include "ShooterControl.h"
#include "ShooterSolenoidControl.h"
#include "GoalAlign.h"
#include "AlignVerticalAndHorizontal.h"

CenterGoalAuto::CenterGoalAuto()
{
	AddSequential(new AlignVerticalAndHorizontal(0));
	AddSequential(new GoalAlign(0));
	AddSequential(new ShooterControl(-3200, .2));
	AddSequential(new ShooterControl(6000, 1));
	AddSequential(new ShooterSolenoidControl());
}
