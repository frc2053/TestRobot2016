#include "RollerForward.h"

RollerForward::RollerForward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intakeSubsystem.get());
}

// Called just before this Command runs the first time
void RollerForward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RollerForward::Execute()
{
	Robot::intakeSubsystem->Intake(1);
}

// Make this return true when this Command no longer needs to run execute()
bool RollerForward::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void RollerForward::End()
{
	Robot::intakeSubsystem->Intake(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerForward::Interrupted()
{

}
