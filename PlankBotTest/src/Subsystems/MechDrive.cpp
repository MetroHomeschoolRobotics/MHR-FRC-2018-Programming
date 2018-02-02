#include "ctre/Phoenix.h"
#include "MechDrive.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

MechDrive::MechDrive() : frc::Subsystem("MechDrive") {

	frontLeft = RobotMap::tankDriveFrontLeft;
    frontRight = RobotMap::tankDriveFrontRight;
    rearRight = RobotMap::tankDriveRearRight;
    rearLeft = RobotMap::tankDriveRearLeft;

}

void MechDrive::InitDefaultCommand() {
}

void MechDrive::Periodic() {
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

	frontLeft->Set(y-x+z);
	rearLeft->Set(y+x+z);
	frontRight->Set(-y-x+z);
	rearRight->Set(-y+x+z);
}
