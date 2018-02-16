/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Clamp.h"

Clamp::Clamp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Clamp::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Clamp::Execute() {
	Joystick *joy = Robot::oi.get()->getDriveJoystick().get();

	Robot::boxLift.get()->Clamp(joy->GetRawAxis(4));

}

// Make this return true when this Command no longer needs to run execute()
bool Clamp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Clamp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Clamp::Interrupted() {

}
