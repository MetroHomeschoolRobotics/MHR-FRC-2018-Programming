#include "../RobotMap.h"
#include "AutonomousSystem.h"

AutonomousSystem::AutonomousSystem() : Subsystem("AutonomousSystem") {

}

int AutonomousSystem::FindDirection() {
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	int len = gameData.length();
	if(len > 0) {
	  if(gameData[0] == 'L')
	  {
		return 0;
	  } else {
		return 1;
	  }
	}
	return -1;
}

void AutonomousSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void AutonomousSystem::ChooseDirection(){

	if (startingPos == 0) {
		AutoLeft();
	} else if (startingPos == 1) {
		AutoRight();
	} else if (startingPos == 2) {
		AutoCenter();
	}
}

void AutonomousSystem::AutoLeft(){
	int direction = FindDirection();

	if (direction == 0){
		DriveH(direction);
	} else {
		DriveI(direction);
	}
}

void AutonomousSystem::AutoRight(){
	int direction = FindDirection();

	if (direction == 0){
		DriveH(direction);
	} else {
		DriveI(direction);
	}
}

void AutonomousSystem::AutoCenter(){
	int direction = FindDirection();

	DriveV(direction);
}

void AutonomousSystem::DriveH(int direction){

	//Move Forward
	//Move Direction * Rotation
	//MoveForward
	//move direction * rotation
	//MoveForward

}

void AutonomousSystem::DriveI(int direction){

}

void AutonomousSystem::DriveV(int direction){

}
