#include "CenterGoalAuto.h"
#include "DriveCommandAuto.h"
#include "ShootHigh.h"
#include "DoNothing.h"
#include "ShooterControl.h"
#include "ShooterSolenoidControl.h"
#include "GoalAlign.h"
#include "AlignVerticalAndHorizontal.h"
#include "AlignParallel.h"

CenterGoalAuto::CenterGoalAuto()
{
	AddSequential(new AlignParallel(0, 101));
	Wait(.5);
	AddSequential(new AlignVerticalAndHorizontal(0));
	//AddSequential(new DriveCommandAuto(0,0,0,.3,-5));
	AddSequential(new ShooterControl(-3200, .2));
	AddSequential(new ShooterControl(6000, 1));
	AddSequential(new ShooterSolenoidControl());
}
