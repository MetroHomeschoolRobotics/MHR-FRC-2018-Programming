#ifndef DriveOcta_H
#define DriveOcta_H

#include <Commands/Command.h>

class DriveOcta : public frc::Command {
public:
	DriveOcta();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveOcta_H
