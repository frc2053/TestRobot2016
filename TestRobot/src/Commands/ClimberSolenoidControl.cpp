#include "ClimberSolenoidControl.h"

ClimberSolenoidControl::ClimberSolenoidControl(bool _direction)
{
	direction = _direction;
	isDone = false;
	Requires(Robot::climberSubsystem.get());
	timer.reset(new Timer());
	timeTarget = pnuematicDelay;
	timeCurrent = 0;
}

// Called just before this Command runs the first time
void ClimberSolenoidControl::Initialize()
{
	isDone = false;
	timer->Reset();
	timer->Start();
	timeTarget = pnuematicDelay;
	timeCurrent = 0;
}

// Called repeatedly when this Command is scheduled to run
void ClimberSolenoidControl::Execute()
{
	isDone = false;
	timeCurrent = timer->Get();
	std::cout << "timeCurrent: " << timeCurrent << std::endl;
	if(timeCurrent >= timeTarget) {
		printf("isDone!\n");
		isDone = true;
	}
	else {
		isDone = false;
	}

	if(direction == true) {
		Robot::climberSubsystem->SetSolenoidForward();
	}
	if(direction == false) {
		Robot::climberSubsystem->SetSolenoidReverse();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ClimberSolenoidControl::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void ClimberSolenoidControl::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimberSolenoidControl::Interrupted()
{

}
