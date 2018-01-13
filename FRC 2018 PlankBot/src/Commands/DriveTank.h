#ifndef DriveTank_H
#define DriveTank_H

#include <Commands/Command.h>

class DriveTank : public frc::Command {
public:
	DriveTank();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveTank_H
