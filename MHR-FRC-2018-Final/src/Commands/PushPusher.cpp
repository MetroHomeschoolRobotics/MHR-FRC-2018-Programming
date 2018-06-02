/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PushPusher.h"


PushPusher::PushPusher(bool in) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	direction = in;
}

// Called just before this Command runs the first time
void PushPusher::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PushPusher::Execute() {
	Robot::boxLift.get()->Pusher(direction);
}

// Make this return true when this Command no longer needs to run execute()
bool PushPusher::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void PushPusher::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PushPusher::Interrupted() {

}
