#ifndef DriveMec_H
#define DriveMec_H

#include <Commands/Command.h>

class DriveMec : public frc::Command {
public:
	DriveMec();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveMec_H
