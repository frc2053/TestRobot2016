#include "Robot.h"
#include "Commands/DrivableDefenseAuto.h"
#include "Commands/CenterGoalAuto.h"
#include "Commands/DoNothing.h"
#include "Commands/LeftGoalAuto.h"
#include "Commands/RightGoalAuto.h"

std::shared_ptr<DriveBaseSubsystem> Robot::driveBaseSubsystem;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::shared_ptr<IntakeSubsystem> Robot::intakeSubsystem;
std::shared_ptr<LEDSubsystem> Robot::ledSubsystem;
std::shared_ptr<VisionClass> Robot::visionClass;
std::unique_ptr<OI> Robot::oi;
PowerDistributionPanel* pdp;
Task* visionTask;

void Vision() {
    Robot::visionClass->visionTest();
}

void Robot::RobotInit() {
	RobotMap::init();

    driveBaseSubsystem.reset(new DriveBaseSubsystem());
    shooterSubsystem.reset(new ShooterSubsystem());
    intakeSubsystem.reset(new IntakeSubsystem());
    ledSubsystem.reset(new LEDSubsystem());

	oi.reset(new OI());

	chooserObstacle = new SendableChooser();
	chooserGoal = new SendableChooser();

	chooserGoal->AddDefault("Center Goal", new CenterGoalAuto());
	chooserGoal->AddObject("Right Goal", new RightGoalAuto());
	chooserGoal->AddObject("Left Goal", new LeftGoalAuto());
	chooserGoal->AddObject("Do Nothing", new DoNothing());

	chooserObstacle->AddDefault("Drivable Defense", new DrivableDefenseAuto());
	//chooserObstacle->AddObject("Portcullis", new PortcullisControl());
	//chooserObstacle->AddObject("Cheval De Frise", new ChevalControl());
	//chooserObstacle->AddObject("Drawbridge", new DrawbridgeControl());
	//chooserObstacle->AddObject("Sally Door", new SallyDoorControl());
	chooserObstacle->AddObject("Do nothing", new DoNothing());
	SmartDashboard::PutData("Goal Chooser", chooserGoal);
	SmartDashboard::PutData("Obstacle Chooser", chooserObstacle);

	visionClass.reset(new VisionClass());
	visionTask = new Task("Vision",(FUNCPTR)Vision,Task::kDefaultPriority + 1);
	pdp = new PowerDistributionPanel();
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
	SmartDashboard::PutNumber("Intake Amperage", pdp->GetCurrent(10));
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);

