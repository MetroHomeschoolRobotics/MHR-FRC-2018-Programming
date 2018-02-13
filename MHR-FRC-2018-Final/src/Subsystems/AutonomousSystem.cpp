#include "AutonomousSystem.h"

AutonomousSystem::AutonomousSystem(OctaDrive *octaDrive, BoxLift *boxLift, Positioning *positioning) : Subsystem("AutonomousSystem") {
	drive = octaDrive;
	lift = boxLift;
	pos = positioning;
	//octaDrive = Robot::octaDrive.get();
	//boxLift = Robot::boxLift.get();
	//positioning = Robot::positioning.get();

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
	drive->Move(0,0,0);
	//Move Direction * Rotation
	while(pos->GetAngle() < 80){
		drive->Move(0.5,0,0);
	}
	//MoveForward
	//move direction * rotation
	//MoveForward
	while(pos->GetDistance() > 400){

	}

}

void AutonomousSystem::DriveI(int direction){

	//Move Forward
	drive->Move(1,1,0);
	//Move Direction * Rotation
	while(pos->GetAngle() < 80){
		drive->Move(0.5,0,0);
	}
	//MoveForward
	//move direction * rotation
	//MoveForward
	while(pos->GetDistance() > 400){
		drive->Move(1,1,0);
	}

}

void AutonomousSystem::DriveV(int direction){

	//Move Forward
	drive->Move(0,0,0);
	//Move Direction * Rotation
	while(pos->GetAngle() < 80){
		drive->Move(0.5,0,0);
	}
	//MoveForward
	//move direction * rotation
	//MoveForward
	while(pos->GetDistance() > 400){
		drive->Move(1,1,0);
	}

}
