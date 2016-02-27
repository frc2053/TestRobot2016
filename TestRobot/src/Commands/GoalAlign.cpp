#include "GoalAlign.h"

GoalAlign::GoalAlign()
{
	Requires(Robot::driveBaseSubsystem.get());
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	calrot = 0;
	adjyaw = 0;
	distanceToCenter = 0;
	speedX = 0;
	SetTimeout(2);
	Robot::driveBaseSubsystem->isAlignedX = false;
}

// Called just before this Command runs the first time
void GoalAlign::Initialize()
{
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	calrot = 0;
	adjyaw = 0;
	distanceToCenter = 0;
	speedX = 0;
	Robot::driveBaseSubsystem->isAlignedX = false;
	//SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void GoalAlign::Execute()
{
	Robot::driveBaseSubsystem->isAlignedX = false;
	distanceToCenter = Robot::visionClass->getDistanceToCenter();
	adjyaw = Robot::driveBaseSubsystem->getAdjYaw();
	calrot = Robot::driveBaseSubsystem->CalculateRotValue(0, 1);
	targetX = Robot::visionClass->getTargetX();
	std::cout << "TargetX: " << targetX << std::endl;

	if(distanceToCenter <= 160)
	{
		speedX = 0.4;
	}
	if(distanceToCenter <= 80)
	{
		speedX = 0.3;
	}
	if(distanceToCenter <= 40)
	{
		speedX = 0.2;
	}

	if(targetX >= (centerX + toleranceX)) {
		inToleranceX = false;
		Robot::driveBaseSubsystem->MecanumDrive(speedX, 0, calrot, adjyaw);
	}
	else if(targetX <= (centerX - toleranceX)) {
		inToleranceX = false;
		Robot::driveBaseSubsystem->MecanumDrive(-speedX, 0, calrot, adjyaw);
	}
	else {
		inToleranceX = true;
	}

	if(inToleranceX) {
		Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
		printf("Target aligned in X dir!\n");
		Robot::driveBaseSubsystem->isAlignedX = true;
		isDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GoalAlign::IsFinished()
{
	return isDone || IsTimedOut();
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
