#ifndef ClimbCommand_H
#define ClimbCommand_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ClimbCommand: public Command
{
public:
	ClimbCommand(float speed = 0, float time = 0);
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
