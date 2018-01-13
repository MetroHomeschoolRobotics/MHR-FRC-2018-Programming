#ifndef DriveTank_H
#define DriveTank_H

#include "../CommandBase.h"

class DriveTank : public CommandBase {
public:
	DriveTank();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveTank_H
