#ifndef IntakeBox_H
#define IntakeBox_H

#include "Commands/Subsystem.h"
#include "../Robot.h"


class IntakeBox : public frc::Command {
public:
	IntakeBox();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakeBox_H
