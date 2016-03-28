#ifndef SlowShooterControl_H
#define SlowShooterControl_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class SlowShooterControl: public Command
{
public:
	SlowShooterControl(float speed = 0, float time = 0);
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
	bool rightBumper2;
	bool leftBumper2;
	bool runOnce;
};

#endif
