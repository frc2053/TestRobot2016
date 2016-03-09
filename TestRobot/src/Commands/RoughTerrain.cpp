#include "RoughTerrain.h"
#include "DriveCommandAuto.h"
#include "ShooterControl.h"

RoughTerrain::RoughTerrain()
{
	AddParallel(new DriveCommandAuto(0, -.8, 0, 2.2, 0));
	AddSequential(new ShooterControl(-1200, 2));
}
