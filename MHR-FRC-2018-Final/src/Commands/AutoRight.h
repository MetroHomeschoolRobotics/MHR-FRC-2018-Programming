#ifndef AutoRight_H
#define AutoRight_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoRight : public frc::Command {
public:
	AutoRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoRight_H
