#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontRightTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackRightTalon;
std::shared_ptr<RobotDrive> RobotMap::driveBaseSubsystemrobotDrive;
std::shared_ptr<AnalogInput> RobotMap::driveBaseSubsystemrangeFinder;

std::shared_ptr<CANTalon> RobotMap::shooterSubsystemshooterTalonLeft;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemshooterTalonRight;
std::shared_ptr<Servo> RobotMap::shooterSubsystemshooterServo;

std::shared_ptr<CANTalon> RobotMap::intakeSubsystemintakeTalon;
std::shared_ptr<Servo> RobotMap::intakeSubsystemintakeServo;

std::shared_ptr<CANTalon> RobotMap::climberSubsystemclimbTalonLeft;
std::shared_ptr<CANTalon> RobotMap::climberSubsystemclimbTalonRight;
std::shared_ptr<DigitalOutput> RobotMap::ledSubsystemGreenLED;
std::shared_ptr<DigitalOutput> RobotMap::ledSubsystemRedLED;
std::shared_ptr<DigitalOutput> RobotMap::ledSubsystemBlueLED;

void RobotMap::init() {
    driveBaseSubsystemfrontLeftTalon.reset(new CANTalon(8));
    driveBaseSubsystemfrontRightTalon.reset(new CANTalon(6));
    driveBaseSubsystembackLeftTalon.reset(new CANTalon(9));
    driveBaseSubsystembackRightTalon.reset(new CANTalon(2));
    driveBaseSubsystemrangeFinder.reset(new AnalogInput(0));
    
    driveBaseSubsystemrobotDrive.reset(new RobotDrive(driveBaseSubsystemfrontLeftTalon, driveBaseSubsystembackLeftTalon,
              driveBaseSubsystemfrontRightTalon, driveBaseSubsystembackRightTalon));
    
    driveBaseSubsystemrobotDrive->SetSafetyEnabled(false);
        driveBaseSubsystemrobotDrive->SetExpiration(0.1);
        driveBaseSubsystemrobotDrive->SetSensitivity(0.5);
        driveBaseSubsystemrobotDrive->SetMaxOutput(1.0);

    driveBaseSubsystemrobotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
    driveBaseSubsystemrobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);

    shooterSubsystemshooterTalonLeft.reset(new CANTalon(4));
    shooterSubsystemshooterTalonRight.reset(new CANTalon(3));
    shooterSubsystemshooterTalonLeft->SetControlMode(CANTalon::kVoltage);
    shooterSubsystemshooterTalonLeft->SetVoltageCompensationRampRate(24.0);

    shooterSubsystemshooterTalonRight->SetControlMode(CANTalon::kVoltage);
    shooterSubsystemshooterTalonRight->SetVoltageCompensationRampRate(24.0);
    //shooterSubsystemshooterTalonRight->SetFeedbackDevice(CANTalon::QuadEncoder);
    //shooterSubsystemshooterTalonRight->SetControlMode(CANTalon::ControlMode::kSpeed);
    //shooterSubsystemshooterTalonRight->ConfigEncoderCodesPerRev(256);
    //shooterSubsystemshooterTalonRight->Set(300);
    //shooterSubsystemshooterTalonRight->SetP(2);
	//shooterSubsystemshooterTalonRight->SetI(0);
	//shooterSubsystemshooterTalonRight->SetD(20);
    //feed forward 1.41

    shooterSubsystemshooterServo.reset(new Servo(0));

    intakeSubsystemintakeTalon.reset(new CANTalon(4));
    intakeSubsystemintakeServo.reset(new Servo(1));

    climberSubsystemclimbTalonLeft.reset(new CANTalon(5));
    climberSubsystemclimbTalonRight.reset(new CANTalon(7));

    ledSubsystemGreenLED.reset(new DigitalOutput(0));
    ledSubsystemRedLED.reset(new DigitalOutput(1));
    ledSubsystemBlueLED.reset(new DigitalOutput(2));
}
