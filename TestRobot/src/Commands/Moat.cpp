#include "Moat.h"
#include "DriveCommandAuto.h"
#include "ShooterControl.h"

Moat::Moat()
{
	AddParallel(new DriveCommandAuto(0, -.8, 0, 2.4, 0));
	AddSequential(new ShooterControl(-1200, 2));
}
