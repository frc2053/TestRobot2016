#ifndef FlipIntake_H
#define FlipIntake_H

#include "Commands/Command.h"
#include "..\Robot.h"

class FlipIntake: public Command
{
public:
	FlipIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	const float pnuematicDelay = 1;
};

#endif
