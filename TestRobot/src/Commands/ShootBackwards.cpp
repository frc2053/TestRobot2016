#include "ShootBackwards.h"

ShootBackwards::ShootBackwards()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterSubsystem.get());
}

// Called just before this Command runs the first time
void ShootBackwards::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShootBackwards::Execute()
{
	Robot::shooterSubsystem->Shoot(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool ShootBackwards::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShootBackwards::End()
{
	Robot::shooterSubsystem->Shoot(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootBackwards::Interrupted()
{
	Robot::shooterSubsystem->Shoot(0);
}
