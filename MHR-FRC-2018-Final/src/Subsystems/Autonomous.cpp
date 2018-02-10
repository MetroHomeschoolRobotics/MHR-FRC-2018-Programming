#include "Autonomous.h"
#include "../RobotMap.h"

Autonomous::Autonomous() : Subsystem("ExampleSubsystem") {

}

void Autonomous::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Autonomous::ChooseDirection(){
	if (startingPos == 0) {
		AutoLeft(direction);
	} else if (startingPos == 1) {
		AutoRight(direction);
	} else if (startingPos == 2) {
		AutoCenter(direction);
	}
}

void Autonomous::AutoLeft(int direction){
	if (direction == 1){
		DriveH(direction);
	} else {
		DriveI(direction);
	}
}

void Autonomous::AutoRight(int direction){
	if (direction == -1){
			DriveH(direction);
		} else {
			DriveI(direction);
		}
}

void Autonomous::AutoCenter(int direction){
	DriveV(direction);
}

void Autonomous::DriveH(int direction){

	//Move Forward
	//Move Direction * Rotation
	//MoveForward
	//move direction * rotation
	//MoveForward

}

void Autonomous::DriveI(int direction){

}

void Autonomous::DriveV(int direction){

}
