// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "OctaDrive.h"

#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/Drive.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

OctaDrive::OctaDrive() : frc::Subsystem("OctoDrive") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    switchSol1 = RobotMap::octoDriveSwitchSol1;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void OctaDrive::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new Drive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void OctaDrive::Periodic() {
    // Put code here to be run every loop

}

void OctaDrive::Move(double x, double y, double z){
	if (isTank){
		Robot::tankDrive.get()->Move(x,y);
	} else {
		Robot::mechDrive.get()->Move(x,y,z);
	}
}

void OctaDrive::SwitchMode(){
	isTank = !isTank;
	if (isTank){
		RobotMap::octoDriveSwitchSol1.get()->Set(frc::DoubleSolenoid::Value::kForward);
	} else {
		RobotMap::octoDriveSwitchSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
	}

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

