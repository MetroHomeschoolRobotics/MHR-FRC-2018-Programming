#ifndef DRIVE_H
#define DRIVE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Drive: public frc::Command {

public:

	Drive();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:

};

#endif
