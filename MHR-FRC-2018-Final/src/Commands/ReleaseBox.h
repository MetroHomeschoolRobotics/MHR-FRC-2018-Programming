#ifndef ReleaseBox_H
#define ReleaseBox_H

#include "Commands/Subsystem.h"
#include "../Robot.h"


class ReleaseBox : public frc::Command {
public:
	ReleaseBox();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ReleaseBox_H
