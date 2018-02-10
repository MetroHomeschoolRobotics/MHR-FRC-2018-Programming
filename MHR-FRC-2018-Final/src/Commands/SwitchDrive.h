#ifndef SWITCHDRIVE_H
#define SWITCHDRIVE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class SwitchDrive: public frc::Command {

public:

	SwitchDrive();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:

};

#endif
