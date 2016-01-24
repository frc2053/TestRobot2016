#include "ZeroYaw.h"

ZeroYaw::ZeroYaw() {
	printf("ZeroYaw constructor!\n");
	Requires(Robot::driveBaseSubsystem.get());
}

// Called just before this Command runs the first time
void ZeroYaw::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ZeroYaw::Execute() {
	Robot::driveBaseSubsystem->imuRobot->ZeroYaw();
}

// Make this return true when this Command no longer needs to run execute()
bool ZeroYaw::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ZeroYaw::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroYaw::Interrupted() {

}
