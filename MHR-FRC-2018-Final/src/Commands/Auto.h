#ifndef AUTO_H
#define AUTO_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Auto: public frc::Command {

public:

	Auto();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:

};

#endif
