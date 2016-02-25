#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontRightTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackRightTalon;
std::shared_ptr<RobotDrive> RobotMap::driveBaseSubsystemrobotDrive;

std::shared_ptr<CANTalon> RobotMap::shooterSubsystemshooterTalonLeft;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemshooterTalonRight;
std::shared_ptr<DoubleSolenoid> RobotMap::shooterSubsystemshooterSolenoid;

std::shared_ptr<CANTalon> RobotMap::intakeSubsystemintakeTalon;
std::shared_ptr<DoubleSolenoid> RobotMap::intakeSubsystemintakeSolenoid;

std::shared_ptr<CANTalon> RobotMap::climberSubsystemclimbTalonLeft;
std::shared_ptr<CANTalon> RobotMap::climberSubsystemclimbTalonRight;
std::shared_ptr<DoubleSolenoid> RobotMap::climberSubsystemclimbSolenoid;

std::shared_ptr<DigitalOutput> RobotMap::ledSubsystemGreenLED;
std::shared_ptr<DigitalOutput> RobotMap::ledSubsystemRedLED;
std::shared_ptr<DigitalOutput> RobotMap::ledSubsystemBlueLED;

std::shared_ptr<CANTalon> RobotMap::defenseSubsystemTalon;
void RobotMap::init() {
    driveBaseSubsystemfrontLeftTalon.reset(new CANTalon(8));
    driveBaseSubsystemfrontRightTalon.reset(new CANTalon(6));
    driveBaseSubsystembackLeftTalon.reset(new CANTalon(9));
    driveBaseSubsystembackRightTalon.reset(new CANTalon(2));
    
    driveBaseSubsystemrobotDrive.reset(new RobotDrive(driveBaseSubsystemfrontLeftTalon, driveBaseSubsystembackLeftTalon,
              driveBaseSubsystemfrontRightTalon, driveBaseSubsystembackRightTalon));
    
    driveBaseSubsystemrobotDrive->SetSafetyEnabled(false);
        driveBaseSubsystemrobotDrive->SetExpiration(0.1);
        driveBaseSubsystemrobotDrive->SetSensitivity(0.5);
        driveBaseSubsystemrobotDrive->SetMaxOutput(1.0);

    driveBaseSubsystemrobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
    driveBaseSubsystemrobotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);

    shooterSubsystemshooterTalonLeft.reset(new CANTalon(4));
    shooterSubsystemshooterTalonRight.reset(new CANTalon(3));
    shooterSubsystemshooterTalonLeft->SetControlMode(CANTalon::kSpeed);
    //shooterSubsystemshooterTalonLeft->SetVoltageCompensationRampRate(24.0);
    shooterSubsystemshooterTalonLeft->SetFeedbackDevice(CANTalon::QuadEncoder);
    shooterSubsystemshooterTalonLeft->SetP(0);
    shooterSubsystemshooterTalonLeft->SetI(0);
    shooterSubsystemshooterTalonLeft->SetD(0);


    shooterSubsystemshooterTalonRight->SetControlMode(CANTalon::kSpeed);
    //shooterSubsystemshooterTalonRight->SetVoltageCompensationRampRate(24.0);
    shooterSubsystemshooterTalonRight->SetFeedbackDevice(CANTalon::QuadEncoder);
    shooterSubsystemshooterTalonRight->SetP(0);
	shooterSubsystemshooterTalonRight->SetI(0);
	shooterSubsystemshooterTalonRight->SetD(0);
    //feed forward 0.185

    shooterSubsystemshooterSolenoid.reset(new DoubleSolenoid(0,1));

    intakeSubsystemintakeTalon.reset(new CANTalon(1));
    intakeSubsystemintakeTalon->SetSafetyEnabled(false);
    intakeSubsystemintakeSolenoid.reset(new DoubleSolenoid(4,5));

    climberSubsystemclimbTalonLeft.reset(new CANTalon(5));
    climberSubsystemclimbTalonRight.reset(new CANTalon(7));
    climberSubsystemclimbSolenoid.reset(new DoubleSolenoid(2,3));

    ledSubsystemGreenLED.reset(new DigitalOutput(1));
    ledSubsystemRedLED.reset(new DigitalOutput(2));
    ledSubsystemBlueLED.reset(new DigitalOutput(3));

    defenseSubsystemTalon.reset(new CANTalon(10));
}
