#ifndef ShooterControl_H
#define ShooterControl_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShooterControl: public Command
{
public:
	ShooterControl(float speed, float time);
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
};

#endif
