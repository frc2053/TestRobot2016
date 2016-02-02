#include "Robot.h"
#include "Commands/DrivableDefenseAuto.h"
#include "Commands/ShootHighAuto.h"
#include "Commands/DoNothing.h"
#include "vision/vision.h"

std::shared_ptr<DriveBaseSubsystem> Robot::driveBaseSubsystem;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::shared_ptr<IntakeSubsystem> Robot::intakeSubsystem;
std::unique_ptr<OI> Robot::oi;
Task* visionTask;

static void Vision(Robot* robot) {
	visionTest();
}

void Robot::RobotInit() {
	RobotMap::init();

    driveBaseSubsystem.reset(new DriveBaseSubsystem());
    shooterSubsystem.reset(new ShooterSubsystem());
    intakeSubsystem.reset(new IntakeSubsystem());

	oi.reset(new OI());

	chooserObstacle = new SendableChooser();
	chooserGoal = new SendableChooser();
	chooserGoal->AddDefault("High Goal", new ShootHighAuto());
	chooserGoal->AddObject("Do Nothing", new DoNothing());
	chooserObstacle->AddDefault("Drivable Defense", new DrivableDefenseAuto());
	chooserObstacle->AddObject("Do nothing", new DoNothing());

	visionTask = new Task("Vision",(FUNCPTR)Vision,Task::kDefaultPriority + 1);
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
	if(selectedObstacle->IsRunning() == false) {
		selectedGoal->Start();
	}
}

void Robot::TeleopInit() {
	if (selectedObstacle != nullptr) {
		selectedObstacle->Cancel();
	}
	if (selectedGoal != nullptr) {
		selectedGoal->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);

