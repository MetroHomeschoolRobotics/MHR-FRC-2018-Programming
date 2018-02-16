/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OpenClamp.h"


OpenClamp::OpenClamp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::boxLift.get());
}

// Called just before this Command runs the first time
void OpenClamp::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void OpenClamp::Execute() {
	Robot::boxLift->Clamp(false);
}

// Make this return true when this Command no longer needs to run execute()
bool OpenClamp::IsFinished() {
	return !Robot::oi.get()->getClampOutButton()->Get();;
}

// Called once after isFinished returns true
void OpenClamp::End() {
	Robot::boxLift.get()->ClampReset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenClamp::Interrupted() {

}
