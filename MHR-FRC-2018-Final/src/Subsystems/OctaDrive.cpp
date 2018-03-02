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


void OctaDrive::UpdateStatFile() {
	ofstream statfile ("/home/lvuser/stats.txt");
	if (statfile.is_open())
	{
		statfile << "{";
		statfile << "\"GyroAngle\":" << Robot::positioning.get()->GetAngle() << ",";
		statfile << "\"Distance\":" << Robot::positioning.get()->GetDistance() << ",";
		statfile << "\"FrontLeft\":" << Robot::positioning.get()->GetFrontLeftDistance() << ",";
		statfile << "\"FrontRight\":" << Robot::positioning.get()->GetFrontRightDistance() << ",";
		statfile << "\"RearLeft\":" << Robot::positioning.get()->GetRearLeftDistance() << ",";
		statfile << "\"RearRight\":" << Robot::positioning.get()->GetRearRightDistance() << ",";
		if (IsTankDrive()){
			statfile << "\"DriveMode\": \"Tank\"";
		} else {
			statfile << "\"DriveMode\": \"Mecanum\"";
		}
		statfile << "}";
		statfile.close();
	}
	else cout << "Unable to open file";
}

