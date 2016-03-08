#include "TestAuto.h"
#include "DriveCommandAuto.h"
#include "ShootHigh.h"
#include "DoNothing.h"
#include "ShooterControl.h"
#include "ShooterSolenoidControl.h"
#include "GoalAlign.h"
#include "AlignVerticalAndHorizontal.h"

TestAuto::TestAuto()
{
	//printf("constructor for test auto!\n");
	AddSequential(new AlignVerticalAndHorizontal());
	AddSequential(new GoalAlign());
	AddSequential(new ShooterControl(-3200, .2));
	AddSequential(new ShooterControl(6000, 1));
	AddSequential(new ShooterSolenoidControl());
	//printf("after sequential for test auto!\n");
}
