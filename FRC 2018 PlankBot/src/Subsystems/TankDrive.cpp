#include "TankDrive.h"
#include "../RobotMap.h"

TankDrive::TankDrive() : Subsystem("ExampleSubsystem") {

}

void TankDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void TankDrive::Drive(int leftSpeed, int rightSpeed) {

}
