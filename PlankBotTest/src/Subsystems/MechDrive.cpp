// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "ctre/Phoenix.h"

#include "MechDrive.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/Drive.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

MechDrive::MechDrive() : frc::Subsystem("MechDrive") {
    frontLeft = RobotMap::tankDriveFrontLeft;
    frontRight = RobotMap::tankDriveFrontRight;
    rearRight = RobotMap::tankDriveRearRight;
    rearLeft = RobotMap::tankDriveRearLeft;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void MechDrive::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new Drive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void MechDrive::Periodic() {
    // Put code here to be run every loop

}

void MechDrive::Move(double x, double y, double z){
	if(fabs(x) < threshold) {
		x = 0;
	}
	if(fabs(y) < threshold) {
		y = 0;
	}
	if(fabs(z) < threshold) {
		z = 0;
	}
	frontLeft->Set(y+x+z);
	rearLeft->Set(y-x+z);
	frontRight->Set(y-x-z);
	rearRight->Set(y+x-z);

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

