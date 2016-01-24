#ifndef RollerBackwards_H
#define RollerBackwards_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class RollerBackwards: public Command
{
public:
	RollerBackwards();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
