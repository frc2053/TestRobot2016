#include "Robot.h"
#include "Commands/Moat.h"
#include "Commands/RockWall.h"
#include "Commands/Ramparts.h"
#include "Commands/RoughTerrain.h"
#include "Commands/CenterGoalAuto.h"
#include "Commands/DoNothing.h"
#include "Commands/LeftGoalAuto.h"
#include "Commands/RightGoalAuto.h"
#include "Commands/TestAuto.h"
#include "Commands/AlignParallel.h"

std::shared_ptr<DriveBaseSubsystem> Robot::driveBaseSubsystem;
std::shared_ptr<ShooterSubsystem> Robot::shooterSubsystem;
std::shared_ptr<IntakeSubsystem> Robot::intakeSubsystem;
std::shared_ptr<ClimberSubsystem> Robot::climberSubsystem;
std::shared_ptr<LEDSubsystem> Robot::ledSubsystem;
std::shared_ptr<VisionClass> Robot::visionClass;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<NetworkTable> Robot::table;
std::shared_ptr<PIDController> Robot::visionAlignPID;
PowerDistributionPanel* pdp;
Task* visionTask;

void Vision() {
   // Robot::visionClass->visionTest();
}

void Robot::RobotInit() {
	RobotMap::init();

    driveBaseSubsystem.reset(new DriveBaseSubsystem());
    shooterSubsystem.reset(new ShooterSubsystem());
    intakeSubsystem.reset(new IntakeSubsystem());
    climberSubsystem.reset(new ClimberSubsystem());
    ledSubsystem.reset(new LEDSubsystem());

	oi.reset(new OI());

	chooserObstacle = new SendableChooser();
	chooserGoal = new SendableChooser();

	chooserGoal->AddDefault("Center Goal", new CenterGoalAuto());
	chooserGoal->AddObject("Right Goal", new RightGoalAuto());
	chooserGoal->AddObject("Left Goal", new LeftGoalAuto());
	chooserGoal->AddObject("Do Nothing", new DoNothing(15));
	chooserGoal->AddObject("TestAuto", new TestAuto());

	chooserObstacle->AddDefault("Rough Terrain", new RoughTerrain());
	//chooserObstacle->AddObject("Portcullis", new PortcullisControl());
	//chooserObstacle->AddObject("Cheval De Frise", new ChevalControl());
	//chooserObstacle->AddObject("Drawbridge", new DrawbridgeControl());
	//chooserObstacle->AddObject("Sally Door", new SallyDoorControl());
	chooserObstacle->AddObject("Rockwall", new RockWall());
	chooserObstacle->AddObject("Ramparts", new Ramparts());
	chooserObstacle->AddObject("Moat", new Moat());
	chooserObstacle->AddObject("Do nothing", new DoNothing(15));
	SmartDashboard::PutData("Goal Chooser", chooserGoal);
	SmartDashboard::PutData("Obstacle Chooser", chooserObstacle);

	visionClass.reset(new VisionClass());
	visionTask = new Task("Vision",(FUNCPTR)Vision,Task::kDefaultPriority + 1);
	pdp = new PowerDistributionPanel();
	Robot::driveBaseSubsystem->imuRobot->ZeroYaw();

    table = NetworkTable::GetTable("vision");
  }

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	started = false;
	selectedObstacle = (Command*) chooserObstacle->GetSelected();
	selectedGoal = (Command*) chooserGoal->GetSelected();
	selectedObstacle->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	if(selectedObstacle->IsRunning() == false && started == false) {
		selectedGoal->Start();
		started = true;
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
	//SmartDashboard::PutNumber("Front Left Amperage", pdp->GetCurrent(3));
	//SmartDashboard::PutNumber("Front Right Amperage", pdp->GetCurrent(14));
	//SmartDashboard::PutNumber("Back Left Amperage", pdp->GetCurrent(0));
	//SmartDashboard::PutNumber("Back Right Amperage", pdp->GetCurrent(15));
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);

