#ifndef TankDrive_H
#define TankDrive_H

#include <Commands/Subsystem.h>

class TankDrive : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	TankDrive();
	void InitDefaultCommand();
	void Drive(int leftSpeed, int rightSpeed);
};

#endif  // TankDrive_H
