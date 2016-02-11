#ifndef ShooterSolenoidControl_H
#define ShooterSolenoidControl_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShooterSolenoidControl: public Command
{
public:
	ShooterSolenoidControl(int _direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int direction;
	bool isDone;
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	const float pnuematicDelay = 0.1;
};

#endif
