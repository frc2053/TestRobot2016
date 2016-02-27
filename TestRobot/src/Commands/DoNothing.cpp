#include "DoNothing.h"

DoNothing::DoNothing(float inputTime)
{
	Requires(Robot::driveBaseSubsystem.get());
	time_timer = 0;
	time_run = inputTime;
	timer = new Timer();
	NothingDone = false;
}

// Called just before this Command runs the first time
void DoNothing::Initialize()
{
	time_timer = 0;
	timer->Reset();
	timer->Start();
	NothingDone = false;
}

// Called repeatedly when this Command is scheduled to run
void DoNothing::Execute()
{
	time_timer = timer->Get();
	//printf("timer %3.2f" ,time_timer);
	if(time_timer >= time_run)
	{
		NothingDone = true;
	}
	else
	{
		NothingDone = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DoNothing::IsFinished()
{
	return NothingDone;
}

// Called once after isFinished returns true
void DoNothing::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoNothing::Interrupted()
{

}
