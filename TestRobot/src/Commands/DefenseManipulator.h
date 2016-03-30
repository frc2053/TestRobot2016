#ifndef DefenseManipulator_H
#define DefenseManipulator_H

#include "Commands/Command.h"
#include "../Robot.h"

class DefenseManipulator: public Command
{
public:
	DefenseManipulator(float speed = 0, float time = 0);
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
