#ifndef ShooterControl_H
#define ShooterControl_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShooterControl: public Command
{
public:
	ShooterControl(float speed = 0, float time = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	float inputSpeed;
	bool isDone;
	bool buttonAPressed;
	bool buttonBPressed;
	float axis;
};

#endif
