#include "RotateToAngleAuto.h"
#include "DriveCommandAuto.h"

RotateToAngleAuto::RotateToAngleAuto(float offset)
{
	float angle = Robot::driveBaseSubsystem->getAdjYaw();
	AddSequential(new DriveCommandAuto(0, 0, 0, 1, angle + offset));
}
