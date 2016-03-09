#include "RightGoalAuto.h"
#include "DriveCommandAuto.h"
#include "GoalAlign.h"
#include "ShooterControl.h"
#include "ShooterSolenoidControl.h"
#include "AlignVerticalAndHorizontal.h"

RightGoalAuto::RightGoalAuto()
{
	AddSequential(new DriveCommandAuto(0, -.8, 0, .5, 0)); //drive in rough direction of goal
	AddSequential(new DriveCommandAuto(-.8, 0, 0, 0.75, -45)); //slide to the right (one hop this time) a little and rotate to 45
	AddSequential(new AlignVerticalAndHorizontal(-45)); //align 120 inches away from the goal
	AddSequential(new GoalAlign(-45));
	AddSequential(new ShooterControl(-3200, .2));
	AddSequential(new ShooterControl(6000, 1));
	AddSequential(new ShooterSolenoidControl());
}
