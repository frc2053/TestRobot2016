#include "Ramparts.h"
#include "DriveCommandAuto.h"
#include "ShooterControl.h"

Ramparts::Ramparts()
{
	AddParallel(new DriveCommandAuto(0, -.8, 0, 2.4, 0));
	AddSequential(new ShooterControl(-1200, 2));
}
