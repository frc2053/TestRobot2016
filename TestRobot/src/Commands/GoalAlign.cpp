#include "GoalAlign.h"

GoalAlign::GoalAlign()
{
	Requires(Robot::driveBaseSubsystem.get());
	isDone = false;
	targetX = 0;
	inTolerance = false;
	calrot = 0;
	adjyaw = 0;
	distance = 0;
	speed = 0;
}

// Called just before this Command runs the first time
void GoalAlign::Initialize()
{
	isDone = false;
	targetX = 0;
	inTolerance = false;
	calrot = 0;
	adjyaw = 0;
	distance = 0;
	speed = 0;
}

// Called repeatedly when this Command is scheduled to run
void GoalAlign::Execute()
{
	distance = getDistance();
	adjyaw = Robot::driveBaseSubsystem->getAdjYaw();
	calrot = Robot::driveBaseSubsystem->CalculateRotValue(0, 1);
	targetX = getTargetX();
	std::cout << "TargetX: " << targetX << std::endl;
	if(distance <= 160)
	{
		speed = 0.3;
	}
	if(distance <= 80)
	{
		speed = 0.25;
	}
	if(distance <= 40)
	{
		speed = 0.20;
	}
	if(distance <= 20)
	{
		speed = 0.18;
	}
	if(targetX >= (centerX + tolerance)) {
		inTolerance = false;
		Robot::driveBaseSubsystem->MecanumDrive(speed, 0, calrot, adjyaw);
	}
	else if(targetX <= (centerX - tolerance)) {
		inTolerance = false;
		Robot::driveBaseSubsystem->MecanumDrive(-speed, 0, calrot, adjyaw);
	}
	else {
		inTolerance = true;
	}
	if(inTolerance) {
		Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
		printf("Target aligned!\n");
		isDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GoalAlign::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void GoalAlign::End()
{
	Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoalAlign::Interrupted()
{
	Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
}
