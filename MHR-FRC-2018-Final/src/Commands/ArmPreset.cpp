/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ArmPreset.h"

ArmPreset::ArmPreset(int target) {
	_boxLift = Robot::boxLift.get();
	//Requires(_boxLift);
	_target = target;
}

// Called just before this Command runs the first time
void ArmPreset::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ArmPreset::Execute() {
	int current = _boxLift->GetArmHeight();
	double move = 0;
	if (current < _target){
		move = 1;
	} else {
		move = -1;
	}

	if (abs(current - _target) < 500){
		move /= 4;
	}

	_boxLift->Rotate(move);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmPreset::IsFinished() {
	return abs(_boxLift->GetArmHeight() - _target) < 15;
}

// Called once after isFinished returns true
void ArmPreset::End() {
	_boxLift->Rotate(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmPreset::Interrupted() {
	_boxLift->Rotate(0);
}
