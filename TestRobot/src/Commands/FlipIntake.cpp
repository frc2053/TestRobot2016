#include "FlipIntake.h"

FlipIntake::FlipIntake()
{
	std::cout << "shooterControl constructor!" << std::endl;
	isDone = false;
	Requires(Robot::intakeSubsystem.get());
	timer.reset(new Timer());
	timeTarget = pnuematicDelay;
	timeCurrent = 0;
}

// Called just before this Command runs the first time
void FlipIntake::Initialize()
{
	std::cout << "Init function!" << std::endl;
	isDone = false;
	timer->Reset();
	timer->Start();
	timeTarget = pnuematicDelay;
	timeCurrent = 0;
}

// Called repeatedly when this Command is scheduled to run
void FlipIntake::Execute()
{
	isDone = false;
	timeCurrent = timer->Get();
	std::cout << "timeCurrent: " << timeCurrent << std::endl;
	if(timeCurrent >= timeTarget) {
		Robot::intakeSubsystem->SetIntakeSolenoidReverse();
		//printf("isDone!\n");
		isDone = true;
	}
	else {
		Robot::intakeSubsystem->SetIntakeSolenoidForward();
		isDone = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool FlipIntake::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void FlipIntake::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlipIntake::Interrupted()
{

}
