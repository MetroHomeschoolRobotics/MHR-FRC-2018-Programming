#ifndef DriveOcta_H
#define DriveOcta_H

#include "../CommandBase.h"

class DriveOcta : public CommandBase {
public:
	DriveOcta();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveOcta_H
