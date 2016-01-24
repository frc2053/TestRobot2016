#ifndef RetractIntake_H
#define RetractIntake_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class RetractIntake: public Command
{
public:
	RetractIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
