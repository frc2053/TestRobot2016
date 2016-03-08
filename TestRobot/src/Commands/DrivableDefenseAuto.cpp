#include "DrivableDefenseAuto.h"
#include "DriveCommandAuto.h"
#include "ShooterControl.h"

DrivableDefenseAuto::DrivableDefenseAuto()
{
	printf("constructor for drivable defense!\n");
	//AddParallel(new DriveCommandAuto(0, -.8, 0, 1.5, 0));
	AddParallel(new DriveCommandAuto(0, -.8, 0, 2, 0));
	AddSequential(new ShooterControl(-1200, 2));
	printf("after sequential for defense auto!\n");
}
