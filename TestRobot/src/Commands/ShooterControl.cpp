#include "ShooterControl.h"

ShooterControl::ShooterControl(float speed, float target)
{
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
	timeCurrent = 0;
	timeTarget = target;
	inputSpeed = speed;
	isDone = false;

}

// Called just before this Command runs the first time
void ShooterControl::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterControl::Execute()
{
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		Robot::shooterSubsystem->Shoot(1);
		isDone = true;

	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::shooterSubsystem->Shoot(0);
			isDone = true;
		}
		else {
			Robot::shooterSubsystem->Shoot(inputSpeed);
			isDone = false;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterControl::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void ShooterControl::End()
{
	timer.reset();
	Robot::shooterSubsystem->Shoot(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterControl::Interrupted()
{
	Robot::shooterSubsystem->Shoot(0);
}
