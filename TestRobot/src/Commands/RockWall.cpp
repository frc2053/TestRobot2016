#include "RockWall.h"
#include "DriveCommandAuto.h"
#include "ShooterControl.h"

RockWall::RockWall()
{
	AddParallel(new DriveCommandAuto(0, -1, 0, 2.4, 0));
	AddSequential(new ShooterControl(-1200, 2));
}
