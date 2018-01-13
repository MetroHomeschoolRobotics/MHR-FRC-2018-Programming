#ifndef MecanumDrive_H
#define MecanumDrive_H

#include <Commands/Subsystem.h>

class MecanumDrive : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	MecanumDrive();
	void InitDefaultCommand();
};

#endif  // MecanumDrive_H
