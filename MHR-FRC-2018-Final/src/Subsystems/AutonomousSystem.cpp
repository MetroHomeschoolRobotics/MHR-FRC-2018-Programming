#include "AutonomousSystem.h"
#include <stdlib.h>

AutonomousSystem::AutonomousSystem(OctaDrive *octaDrive, BoxLift *boxLift, Positioning *positioning) : Subsystem("AutonomousSystem") {
	drive = octaDrive;
	lift = boxLift;
	pos = positioning;
	//octaDrive = Robot::octaDrive.get();
	//boxLift = Robot::boxLift.get();
	//positioning = Robot::positioning.get();
	completed = false;
}

void AutonomousSystem::Complete(){
	completed = true;
}

int AutonomousSystem::FindDirection() {
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	std::printf("Game Data: %s \n", gameData.c_str());
	int len = gameData.length();
	int direction = -1;
	if(len > 0) {
	  if(gameData[0] == 'L')
	  {
		  direction = 0;
	  } else if(gameData[0] == 'R') {
		  direction = 1;
	  } else {
		  direction = -1;
	  }
	}
	int tries = 5;
	int i = 0;
	while(direction == -1 && i < tries){
		Wait(1);
		direction = FindDirection();
	}

	return direction;
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
	completed = false;

	int direction = FindDirection();
	std::printf("Direction: %d \n", direction);

	if (direction == 0){
		DriveI(direction);
	} else {
		DriveH(direction);
	}
}

void AutonomousSystem::AutoRight(){
	completed = false;

	int direction = FindDirection();
	std::printf("Direction: %d \n", direction);

	if (direction == 0){
		DriveH(direction);
	} else {
		DriveI(direction);
	}
}

void AutonomousSystem::AutoCenter(){
	completed = false;

	int direction = FindDirection();

	DriveV(direction);
}

void AutonomousSystem::DriveH(int direction){
	std::printf("Drive Pattern H \n");
	//Move Forward

	//Wait(1);
	while(pos->GetDistance() > 70 && !completed){
		drive->Move(0,-.4,0);
	}
	/*
	while(pos->GetDistance() > 15 && !completed){
		drive->Move(0,0,0);
	}*/

	drive->Move(0,0,0);
}

void AutonomousSystem::DriveI(int direction){
	std::printf("Drive Pattern I \n");
		//Move Forward

	//drive->SwitchMode();

		//Wait(1);
		while(pos->GetDistance() > 70 && !completed){
			drive->Move(-0.05,-.4,0);
		}
		/*
		while(pos->GetDistance() > 15 && !completed){
			drive->Move(0,0,0);
		}*/

		drive->Move(0,0,0);

		std::printf("Arm Height %d\n", lift->GetArmHeight());
		while(lift->GetArmHeight() < 5500 && !completed){
			lift->Rotate(.5);
		}
		lift->Rotate(0);

		lift->DroolBox();
}

void AutonomousSystem::DriveV(int direction){
	int distanceY = pos->GetDistance() - 30;

	std::printf("Drive Pattern V \n");
	//Move Forward

	drive->SwitchMode();

	Wait(1);

	while(pos->GetDistance() >= distanceY && !completed){
		drive->Move(0,-0.4,0);
	}

	if (direction == 0){
		/*
		 drive->Move(-.5, 0, 0);
		Wait(1);
		drive->Move(0, -.5, 0);
		Wait(1);
		drive->Move(.5, 0, 0);
		while(pos->GetDistance() >= 70 && !completed){
			drive->Move(0,-0.5,0);
		}
		 */
		while(pos->GetDistance() >= 70 && !completed){
			drive->Move(-0.6,-0.5,0);
		}
	} else {
		while(pos->GetDistance() >= 70 && !completed){
			drive->Move(0.6,-0.5,0);
		}
	}
	drive->Move(0,0,0);

	std::printf("Arm Height %d\n", lift->GetArmHeight());
	while(lift->GetArmHeight() < 5500 && !completed){
		lift->Rotate(.5);
	}
	lift->Rotate(0);

	lift->DroolBox();

	/*	Wait(1);

	int i = 1;

	while(i == 1  && !completed){
		drive->Move(.5,0,0);
		Wait();
		drive->Move(0,0,0);
	}

	drive->Move(0,0,0);

	Wait(5);

	drive->Move(0,0,0);

	//Move Direction * Rotation
	while(pos->GetAngle() < 80){
		//drive->Move(0.5,0,0);
		return;
	}
	//MoveForward
	//move direction * rotation
	//MoveForward
	while(pos->GetDistance() > 400){
		//drive->Move(1,1,0);
		return;
	}
*/
}
