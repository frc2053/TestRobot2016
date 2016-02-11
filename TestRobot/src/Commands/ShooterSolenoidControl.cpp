#include "ShooterSolenoidControl.h"

ShooterSolenoidControl::ShooterSolenoidControl(int _direction)
{
	direction = _direction;
	isDone = false;
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
	timeTarget = pnuematicDelay;
	timeCurrent = 0;
}

// Called just before this Command runs the first time
void ShooterSolenoidControl::Initialize()
{
	isDone = false;
	timeTarget = pnuematicDelay;
	timeCurrent = 0;
}

// Called repeatedly when this Command is scheduled to run
void ShooterSolenoidControl::Execute()
{
	isDone = false;
	timeCurrent = timer->Get();
	if(timeCurrent >= timeTarget) {
		isDone = true;
	}
	else {
		isDone = false;
	}
	if(direction == 1) {
		Robot::shooterSubsystem->SetSolenoidForward();
	}
	if(direction == 0) {
		Robot::shooterSubsystem->SetSolenoidReverse();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterSolenoidControl::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void ShooterSolenoidControl::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterSolenoidControl::Interrupted()
{

}
