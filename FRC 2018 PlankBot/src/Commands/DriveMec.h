#ifndef DriveMec_H
#define DriveMec_H

#include "../CommandBase.h"

class DriveMec : public CommandBase {
public:
	DriveMec();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveMec_H
