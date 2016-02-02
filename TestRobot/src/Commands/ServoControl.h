#ifndef ServoControl_H
#define ServoControl_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ServoControl: public Command
{
public:
	ServoControl(float pwm);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float inputPWM;
};

#endif
