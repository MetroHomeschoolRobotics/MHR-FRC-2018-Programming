#ifndef OctanumDrive_H
#define OctanumDrive_H

#include <Commands/Subsystem.h>

class OctanumDrive : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	OctanumDrive();
	void InitDefaultCommand();
};

#endif  // OctanumDrive_H
