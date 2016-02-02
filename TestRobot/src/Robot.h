#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"

#include "Commands/DrivableDefenseAuto.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Subsystems/IntakeSubsystem.h"

#include "OI.h"
#include "Subsystems/DriveBaseSubsystem.h"

class Robot : public IterativeRobot {
public:
	static std::unique_ptr<OI> oi;
    static std::shared_ptr<DriveBaseSubsystem> driveBaseSubsystem;
    static std::shared_ptr<ShooterSubsystem> shooterSubsystem;
    static std::shared_ptr<IntakeSubsystem> intakeSubsystem;

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
private:
	SendableChooser* chooserObstacle;
	SendableChooser* chooserGoal;
	Command* obstacleCommand;
	Command* goalCommand;
	Command* selectedObstacle;
	Command* selectedGoal;
};
#endif
