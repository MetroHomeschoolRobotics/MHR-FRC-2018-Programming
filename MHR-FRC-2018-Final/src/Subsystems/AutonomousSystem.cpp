#include "AutonomousSystem.h"
#include <stdlib.h>

AutonomousSystem::AutonomousSystem() : Subsystem("AutonomousSystem") {
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
