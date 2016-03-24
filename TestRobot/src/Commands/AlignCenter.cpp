#include "AlignCenter.h"

AlignCenter::AlignCenter()
{
	Requires(Robot::driveBaseSubsystem.get());
	distanceToCenter = 0;
	adjyaw = 0;
	speedRot = 0;
	isDone = false;
	XAxis = 0;
	YAxis = 0;
	RotAxis = 0;
}

// Called just before this Command runs the first time
void AlignCenter::Initialize()
{
	distanceToCenter = 0;
	adjyaw = 0;
	speedRot = 0;
	isDone = false;
	XAxis = 0;
	YAxis = 0;
	RotAxis = 0;
}

// Called repeatedly when this Command is scheduled to run
void AlignCenter::Execute()
{
	XAxis = Robot::oi->getdriverJoystick()->GetRawAxis(0);
	YAxis = Robot::oi->getdriverJoystick()->GetRawAxis(1);
	RotAxis = Robot::oi->getdriverJoystick()->GetRawAxis(4);
	distanceToCenter = Robot::table->GetNumber("center", 0.0);
	std::cout << "DistanceToCenter: " << distanceToCenter << std::endl;
	adjyaw = Robot::driveBaseSubsystem->getAdjYaw();
	speedRot = AlignCenter::CalculateSpeedValue(distanceToCenter);
	std::cout << "speedRot: " << speedRot << std::endl;

	if(abs(XAxis) > .2 || abs(YAxis) > .2 || abs(RotAxis) > .2) {
		//isDone = true;
		std::cout << "Override!" << std::endl;
	}

	if(speedRot == 0) {
		std::cout << "speedRot == 0!" << std::endl;
		isDone = true;
	}

	Robot::driveBaseSubsystem->MecanumDrive(0, 0, speedRot, adjyaw);
	Wait(0.1 + (0.0011 * abs(distanceToCenter)));
	Robot::driveBaseSubsystem->MecanumDrive(0, 0, 0, adjyaw);
	Wait(.08);
}

// Make this return true when this Command no longer needs to run execute()
bool AlignCenter::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void AlignCenter::End()
{
	std::cout << "DistanceToCenter: " << distanceToCenter << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignCenter::Interrupted()
{

}

float AlignCenter::CalculateSpeedValue(int toCenter) {
	float returnedSpeed = 0;
	/*if(toCenter > 200) {
		returnedSpeed = -.25;
	}
	else if(toCenter > 100) {
		returnedSpeed = -.25;
	}
	else if(toCenter > 50) {
		returnedSpeed = -.25;
	}
	else if(toCenter > 25) {
		returnedSpeed = -.25;
	}

	if(toCenter < -200) {
		returnedSpeed = .25;
	}
	else if(toCenter < -100) {
		returnedSpeed = .25;
	}
	else if(toCenter < -50) {
		returnedSpeed = .25;
	}
	else if(toCenter < -25) {
		returnedSpeed = .25;
	}

	if(abs(toCenter) < 10) {
		returnedSpeed = 0;
	}*/

	if(toCenter >= 15) {
		returnedSpeed = -.25;
	}

	if(toCenter <= -15) {
		returnedSpeed = .25;
	}

	if(abs(toCenter) < 15) {
		returnedSpeed = 0;
	}

	return returnedSpeed;
}
