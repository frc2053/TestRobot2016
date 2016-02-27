#ifndef DoNothing_H
#define DoNothing_H

#include "Commands/Command.h"
#include "../Robot.h"

class DoNothing: public Command
{
public:
	DoNothing(float inputTime);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer* timer;
	double time_run;
	float time_timer;
	bool NothingDone;
};

#endif
