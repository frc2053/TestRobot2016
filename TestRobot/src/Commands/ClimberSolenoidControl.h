#ifndef ClimberSolenoidControl_H
#define ClimberSolenoidControl_H

#include "Commands/Command.h"
#include "../Robot.h"

class ClimberSolenoidControl: public Command
{
public:
	ClimberSolenoidControl(bool _direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool direction;
	bool isDone;
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	const float pnuematicDelay = 2.5;
};

#endif
