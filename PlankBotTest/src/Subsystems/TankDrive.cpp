#include "ctre/Phoenix.h"
#include "TankDrive.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

TankDrive::TankDrive() : frc::Subsystem("TankDrive") {

    frontLeft = RobotMap::tankDriveFrontLeft;
    frontRight = RobotMap::tankDriveFrontRight;
    rearRight = RobotMap::tankDriveRearRight;
    rearLeft = RobotMap::tankDriveRearLeft;

}

void TankDrive::InitDefaultCommand() {

        SetDefaultCommand(new Drive());

}

void TankDrive::Periodic() {
}

void TankDrive::Move(double x, double y){

	if(fabs(x) < threshold) {
		x = 0;
	}

	if(fabs(y) < threshold) {
		y = 0;
	}
	frontLeft->Set((y-x));
	rearLeft->Set((y-x));
	frontRight->Set((-y-x));
	rearRight->Set((-y-x));
}

