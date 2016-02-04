#include "GoalAlign.h"

GoalAlign::GoalAlign()
{
	Requires(Robot::driveBaseSubsystem.get());
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	inToleranceY = false;
	calrot = 0;
	adjyaw = 0;
	distanceToCenter = 0;
	distanceY = 0;
	speedX = 0;
	speedY = 0;
}

// Called just before this Command runs the first time
void GoalAlign::Initialize()
{
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	inToleranceY = false;
	calrot = 0;
	adjyaw = 0;
	distanceToCenter = 0;
	distanceY = 0;
	speedX = 0;
	speedY = 0;
	//SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void GoalAlign::Execute()
{
	distanceToCenter = getDistanceToCenter();
	distanceY = getDistanceY();
	adjyaw = Robot::driveBaseSubsystem->getAdjYaw();
	calrot = Robot::driveBaseSubsystem->CalculateRotValue(0, 1);
	targetX = getTargetX();
	std::cout << "TargetX: " << targetX << std::endl;

	if(distanceY >= 144) {
		speedY = 1.0;
	}
	if(distanceY >= 120) {
		speedY = .8;
	}
	if(distanceY >= 96) {
		speedY = .6;
	}
	if(distanceY >= 60) {
		speedY = .2;
	}

	speedY = .25;

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

	bool tooClose = distanceY <= (distanceTarget - toleranceY);
	bool tooFar = distanceY >= (distanceTarget + toleranceY);
	std::cout << "distanceY: " << distanceY << std::endl;
	std::cout << "tooClose: " << tooClose << std::endl;
	std::cout << "tooFar: " << tooFar << std::endl;
	if(tooClose) {
		printf("bot is too close!\n");
		inToleranceY = false;
		Robot::driveBaseSubsystem->MecanumDrive(/*speedX*/0, -speedY, calrot, adjyaw);
	}
	else if(tooFar) {
		printf("bol is too far!\n");
		inToleranceY = false;
		Robot::driveBaseSubsystem->MecanumDrive(0, speedY, calrot, adjyaw);
	}
	else {
		printf("inTolerance == true\n");
		inToleranceY = true;
	}

	/*if(targetX >= (centerX + toleranceX)) {
		inToleranceX = false;
		Robot::driveBaseSubsystem->MecanumDrive(speedX, speedY, calrot, adjyaw);
	}
	else if(targetX <= (centerX - toleranceX)) {
		inToleranceX = false;
		Robot::driveBaseSubsystem->MecanumDrive(-speedX, speedY, calrot, adjyaw);
	}
	else {
		inToleranceX = true;
	}*/

	if(/*inToleranceX &&*/ inToleranceY) {
		Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
		printf("Target aligned!\n");
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
