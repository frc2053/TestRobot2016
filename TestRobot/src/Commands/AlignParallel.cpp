#include "AlignParallel.h"

AlignParallel::AlignParallel(float angle, float distanceAway)
{
	Requires(Robot::driveBaseSubsystem.get());
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	calrot = 0;
	adjyaw = 0;
	targetAngle = angle;
	distanceToCenter = 0;
	speedX = 0;
	XAxis = 0;
	YAxis = 0;
	RotAxis = 0;
	distanceTarget = distanceAway;
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
	//SetTimeout(2);
	Robot::driveBaseSubsystem->isAlignedX = false;
	Robot::driveBaseSubsystem->isAlignedY = false;
}

// Called just before this Command runs the first time
void AlignParallel::Initialize()
{
	isDone = false;
	targetX = 0;
	inToleranceX = false;
	calrot = 0;
	adjyaw = 0;
	distanceToCenter = 0;
	speedX = 0;
	Robot::driveBaseSubsystem->isAlignedX = false;
	Robot::driveBaseSubsystem->isAlignedY = false;
	inToleranceY = false;
	distanceY = 0;
	speedY = 0;
}

// Called repeatedly when this Command is scheduled to run
void AlignParallel::Execute()
{
	XAxis = Robot::oi->getdriverJoystick()->GetRawAxis(0);
	YAxis = Robot::oi->getdriverJoystick()->GetRawAxis(1);
	RotAxis = Robot::oi->getdriverJoystick()->GetRawAxis(4);
	Robot::driveBaseSubsystem->isAlignedX = false;
	Robot::driveBaseSubsystem->isAlignedY = false;
	distanceToCenter = Robot::visionClass->getDistanceToCenter();
	adjyaw = Robot::driveBaseSubsystem->getAdjYaw();
	distanceY = Robot::visionClass->getDistanceY();
	calrot = Robot::driveBaseSubsystem->CalculateRotValue(targetAngle, 1);
	targetX = Robot::visionClass->getTargetX();
	//std::cout << "TargetX: " << targetX << std::endl;

	if(XAxis > .2 || YAxis > .2 || RotAxis > .2) {
		isDone = true;
	}

	if(distanceToCenter <= 160)
	{
		speedX = 0.5;
	}
	if(distanceToCenter <= 80)
	{
		speedX = 0.4;
	}
	if(distanceToCenter <= 40)
	{
		speedX = 0.3;
	}

	if(distanceY >= 144) {
		speedY = .4;
	}
	if(distanceY >= 120) {
		speedY = .3;

	}
	if(distanceY >= 96) {
		speedY = .3;
	}
	if(distanceY >= 60) {
		speedY = .3;
	}

	bool tooClose = distanceY < (distanceTarget - toleranceY);
	bool tooFar = distanceY > (distanceTarget + toleranceY);

	if(tooClose) {
		printf("bot is too close!\n");
		inToleranceY = false;
		//Robot::driveBaseSubsystem->MecanumDrive(0, speedY, calrot, adjyaw);
	}
	else if(tooFar) {
		printf("bol is too far!\n");
		inToleranceY = false;
		speedY = speedY * -1;
		//Robot::driveBaseSubsystem->MecanumDrive(0, -speedY, calrot, adjyaw);
	}
	else {
		printf("inTolerance == true\n");
		inToleranceY = true;
	}

	//targetX = targetX - 2;
	if(targetX >= (centerX + toleranceX)) {
		inToleranceX = false;
		//Robot::driveBaseSubsystem->MecanumDrive(speedX, 0, calrot, adjyaw);
	}
	else if(targetX <= (centerX - toleranceX)) {
		inToleranceX = false;
		speedX = speedX * -1;
		//Robot::driveBaseSubsystem->MecanumDrive(-speedX, 0, calrot, adjyaw);
	}
	else {
		inToleranceX = true;
	}

	Robot::driveBaseSubsystem->MecanumDrive(speedX, speedY, calrot, adjyaw);

	if(inToleranceX && inToleranceY) {
		Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
		//printf("Target aligned in X dir!\n");
		Robot::driveBaseSubsystem->isAlignedX = true;
		Robot::driveBaseSubsystem->isAlignedY = true;
		isDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AlignParallel::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void AlignParallel::End()
{
	Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignParallel::Interrupted()
{
	Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, 0);
}
