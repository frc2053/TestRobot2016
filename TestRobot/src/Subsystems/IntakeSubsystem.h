#ifndef IntakeSubsystem_H
#define IntakeSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSubsystem: public Subsystem
{
private:
	std::shared_ptr<CANTalon> intakeTalon;
	std::shared_ptr<DoubleSolenoid> intakeSolenoid;
public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void Intake(float speed);
	void SetIntakeSolenoidForward();
	void SetIntakeSolenoidReverse();
};

#endif
