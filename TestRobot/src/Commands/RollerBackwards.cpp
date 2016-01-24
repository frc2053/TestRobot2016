#include "RollerBackwards.h"

RollerBackwards::RollerBackwards()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void RollerBackwards::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RollerBackwards::Execute()
{
	Robot::intakeSubsystem->Intake(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool RollerBackwards::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void RollerBackwards::End()
{
	Robot::intakeSubsystem->Intake(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerBackwards::Interrupted()
{

}
