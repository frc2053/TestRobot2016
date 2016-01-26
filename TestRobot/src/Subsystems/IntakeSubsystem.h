#ifndef IntakeSubsystem_H
#define IntakeSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSubsystem: public Subsystem
{
private:
	std::shared_ptr<CANTalon> intakeTalon;
	std::shared_ptr<DoubleSolenoid> intakeSolenoid;
	std::shared_ptr<Servo> intakeServo;
public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void Intake(float speed);
	void SolenoidForward();
	void SolenoidBackwards();
	void SetServo(float pwm);
	void SetServoAngle(float angle);
};

#endif
