#include "LEDSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/LEDCommand.h"

LEDSubsystem::LEDSubsystem() : Subsystem("LEDSubsystem")
{
	RedLED = RobotMap::ledSubsystemRedLED;
	GreenLED = RobotMap::ledSubsystemGreenLED;
	BlueLED = RobotMap::ledSubsystemBlueLED;
}

void LEDSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new LEDCommand());
}

void LEDSubsystem::SetRedLED(float value)
{
	RedLED->DisablePWM();
	RedLED->EnablePWM(value);
}

void LEDSubsystem::SetGreenLED(float value)
{
	GreenLED->DisablePWM();
	GreenLED->EnablePWM(value);
}

void LEDSubsystem::SetBlueLED(float value)
{
	BlueLED->DisablePWM();
	BlueLED->EnablePWM(value);
}
