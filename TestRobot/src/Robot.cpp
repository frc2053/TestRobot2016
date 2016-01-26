#include "Robot.h"
#include "Commands/ShootHigh.h"
#include "Commands/DrivableDefenseAuto.h"

std::shared_ptr<DriveBaseSubsystem> Robot::driveBaseSubsystem;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::shared_ptr<IntakeSubsystem> Robot::intakeSubsystem;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();

    driveBaseSubsystem.reset(new DriveBaseSubsystem());
    shooterSubsystem.reset(new ShooterSubsystem());
    intakeSubsystem.reset(new IntakeSubsystem());

	oi.reset(new OI());

	chooserObstacle = new SendableChooser();
	chooserGoal = new SendableChooser();
	chooserGoal->AddDefault("High Goal", new ShootHigh());
	chooserObstacle->AddDefault("Drivable Defense", new DrivableDefenseAuto());
  }

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	selectedObstacle = (Command*) chooserObstacle->GetSelected();
	selectedGoal = (Command*) chooserGoal->GetSelected();
	selectedObstacle->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	//if() {
		selectedGoal->Start();
	//}
}

void Robot::TeleopInit() {
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);

