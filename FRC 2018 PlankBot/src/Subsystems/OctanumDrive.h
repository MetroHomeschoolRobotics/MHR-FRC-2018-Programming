#ifndef OctanumDrive_H
#define OctanumDrive_H

#include <Commands/Subsystem.h>

class OctanumDrive : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	OctanumDrive();
	void InitDefaultCommand();
};

#endif  // OctanumDrive_H
