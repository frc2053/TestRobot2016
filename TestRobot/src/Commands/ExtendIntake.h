#ifndef ExtendIntake_H
#define ExtendIntake_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ExtendIntake: public Command
{
public:
	ExtendIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
