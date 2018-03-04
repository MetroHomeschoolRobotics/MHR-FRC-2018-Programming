#include "OctaDrive.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

OctaDrive::OctaDrive() : frc::Subsystem("OctoDrive") {

    switchSol1 = RobotMap::octoDriveSwitchSol1;

}

void OctaDrive::InitDefaultCommand() {
}

void OctaDrive::Periodic() {
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
		RobotMap::octoDriveSwitchSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
	} else {
		RobotMap::octoDriveSwitchSol1.get()->Set(frc::DoubleSolenoid::Value::kForward);
	}

}

bool OctaDrive::IsTankDrive() {
	return isTank;
}

