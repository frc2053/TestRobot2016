#include "ShootForward.h"

ShootForward::ShootForward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterSubsystem.get());
}

// Called just before this Command runs the first time
void ShootForward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShootForward::Execute()
{
	Robot::shooterSubsystem->Shoot(1);
}

// Make this return true when this Command no longer needs to run execute()
bool ShootForward::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShootForward::End()
{
	Robot::shooterSubsystem->Shoot(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootForward::Interrupted()
{
	Robot::shooterSubsystem->Shoot(0);
}
