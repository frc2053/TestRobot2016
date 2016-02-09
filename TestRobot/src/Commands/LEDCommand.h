#ifndef LEDCommand_H
#define LEDCommand_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class LEDCommand: public Command
{
public:
	LEDCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
