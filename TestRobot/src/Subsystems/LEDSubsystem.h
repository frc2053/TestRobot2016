#ifndef LEDSubsystem_H
#define LEDSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LEDSubsystem: public Subsystem
{
private:
	std::shared_ptr<DigitalOutput> RedLED;
	std::shared_ptr<DigitalOutput> GreenLED;
	std::shared_ptr<DigitalOutput> BlueLED;
public:
	LEDSubsystem();
	void InitDefaultCommand();
	void SetRedLED(float value);
	void SetGreenLED(float value);
	void SetBlueLED(float value);
};

#endif
