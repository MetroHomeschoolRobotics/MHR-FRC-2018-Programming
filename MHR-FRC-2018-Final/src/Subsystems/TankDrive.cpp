#include "ctre/Phoenix.h"
#include "TankDrive.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

TankDrive::TankDrive() : frc::Subsystem("TankDrive") {
    frontLeft = RobotMap::tankDriveFrontLeft;
    frontRight = RobotMap::tankDriveFrontRight;
    rearRight = RobotMap::tankDriveRearRight;
    rearLeft = RobotMap::tankDriveRearLeft;
    positioning = Robot::positioning;
}

void TankDrive::InitDefaultCommand() {
}

void TankDrive::Periodic() {
}

void TankDrive::Move(double x, double y){
	double distance = positioning.get()->GetDistance();
	SmartDashboard::PutNumber("Lidar Distance", distance);

	SmartDashboard::PutNumber("Front Left Enc", frontLeft->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Rear Left Enc", rearLeft->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Front Right Enc", frontRight->GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Rear Right Enc", rearRight->GetSelectedSensorPosition(0));

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

