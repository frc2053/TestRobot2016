#include "DriveBaseSubsystem.h"

#include "../RobotMap.h"
#include "../Commands/DriveCommand.h"

DriveBaseSubsystem::DriveBaseSubsystem() : Subsystem("DriveBaseSubsystem") {
	printf("DriveBaseSubsystem!\n");
    frontLeftTalon = RobotMap::driveBaseSubsystemfrontLeftTalon;
    frontRightTalon = RobotMap::driveBaseSubsystemfrontRightTalon;
    backLeftTalon = RobotMap::driveBaseSubsystembackLeftTalon;
    backRightTalon = RobotMap::driveBaseSubsystembackRightTalon;
    robotDrive = RobotMap::driveBaseSubsystemrobotDrive;
    rangeFinder = RobotMap::driveBaseSubsystemrangeFinder;
	imuRobot = new AHRS(SPI::Port::kMXP);
	tigerDrive = new TigerDrive(imuRobot);
	IMU_Yaw = 0;
	calculatedoffset = 0;
	yawoffset = 0;
}

void DriveBaseSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new DriveCommand());
}

void DriveBaseSubsystem::MecanumDrive(float x, float y, float rot, float gyro)
{
	robotDrive->MecanumDrive_Cartesian(x,y,rot,gyro);
}

float DriveBaseSubsystem::CalculateRotValue(float setAngle, float setSpeed)
{
	return tigerDrive->CalculateRotValue(setAngle, setSpeed);
}

float DriveBaseSubsystem::getAdjYaw()
{
	return tigerDrive->getAdjYaw();
}

void DriveBaseSubsystem::setAdjYaw(float offset)
{
	tigerDrive->setAdjYaw(offset);
}

void DriveBaseSubsystem::setIsRotDone(bool isDone)
{
	tigerDrive->setIsRotDone(isDone);
}

void DriveBaseSubsystem::setIsRotDoneOverride(bool isDone)
{
	tigerDrive->setIsRotDoneOverride(isDone);
}

void DriveBaseSubsystem::setTimesThroughLoop(int timeLoop)
{
	tigerDrive->setTimesThroughLoop(timeLoop);
}

float DriveBaseSubsystem::getImuYaw()
{
	return tigerDrive->getImuYaw();
}

bool DriveBaseSubsystem::getIsRotDone()
{
	return tigerDrive->getisRotDone();
}

bool DriveBaseSubsystem::getIsRotDoneOverride()
{
	return tigerDrive->getisRotDoneOverride();
}

float DriveBaseSubsystem::getDistance() {
	return rangeFinder->GetVoltage();
}
