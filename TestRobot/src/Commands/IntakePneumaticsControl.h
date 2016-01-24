#ifndef IntakePneumaticsControl_H
#define IntakePneumaticsControl_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class IntakePneumaticsControl: public Command
{
public:
	IntakePneumaticsControl(bool inputDir); //true is extend / false is retract
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool direction;
};

#endif
