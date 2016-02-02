#include "DrivableDefenseAuto.h"
#include "DriveCommandAuto.h"

DrivableDefenseAuto::DrivableDefenseAuto()
{
	AddSequential(new DriveCommandAuto(0, 0.5, 0, 0.4, 0));
}
