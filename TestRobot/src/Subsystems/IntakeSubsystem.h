#ifndef IntakeSubsystem_H
#define IntakeSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> intakeTalon;
	std::shared_ptr<DoubleSolenoid> intakeSolenoid;
public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void Intake(float speed);
	void SolenoidForward();
	void SolenoidBackwards();
};

#endif
