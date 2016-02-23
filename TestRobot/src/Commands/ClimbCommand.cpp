#include "ClimbCommand.h"

ClimbCommand::ClimbCommand(float speed, float target)
{
	Requires(Robot::climberSubsystem.get());
	timer.reset(new Timer());
	timeCurrent = 0;
	timeTarget = target;
	inputSpeed = speed;
	isDone = false;

}

// Called just before this Command runs the first time
void ClimbCommand::Initialize()
{
	timer->Reset();
	timer->Start();
	timeCurrent = 0;
	isDone = false;
}

// Called repeatedly when this Command is scheduled to run
void ClimbCommand::Execute()
{
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		Robot::climberSubsystem->ClimbMotor(inputSpeed);
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::climberSubsystem->ClimbMotor(0);
			isDone = true;
		}
		else {
			Robot::climberSubsystem->ClimbMotor(inputSpeed);
			isDone = false;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbCommand::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void ClimbCommand::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbCommand::Interrupted()
{

}
