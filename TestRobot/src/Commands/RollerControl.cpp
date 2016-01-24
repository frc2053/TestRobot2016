#include "RollerControl.h"

RollerControl::RollerControl(float speed, float target)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intakeSubsystem.get());
	timer.reset(new Timer());
	timer->Reset();
	timer->Start();
	timeCurrent = 0;
	timeTarget = target;
	inputSpeed = speed;
	isDone = false;
}

// Called just before this Command runs the first time
void RollerControl::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RollerControl::Execute()
{
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		Robot::intakeSubsystem->Intake(inputSpeed);
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::intakeSubsystem->Intake(0);
			isDone = true;
		}
		else {
			Robot::intakeSubsystem->Intake(inputSpeed);
			isDone = false;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RollerControl::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void RollerControl::End()
{
	Robot::intakeSubsystem->Intake(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerControl::Interrupted()
{

}
