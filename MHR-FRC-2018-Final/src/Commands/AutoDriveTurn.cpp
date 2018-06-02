/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoDriveTurn.h"

AutoDriveTurn::AutoDriveTurn(double angle, double driveX, double driveY, double driveZ) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	startPos = 0;
	targetPos = angle;
	x = driveX;
	y = driveY;
	z = driveZ;
}

// Called just before this Command runs the first time
void AutoDriveTurn::Initialize() {
	startPos = Robot::positioning.get()->GetAngle();
	Robot::octaDrive.get()->Move(x, y, z);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveTurn::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTurn::IsFinished() {
	if (targetPos > 0) {
		return Robot::positioning.get()->GetAngle() < startPos - targetPos;
	} else {
		return Robot::positioning.get()->GetAngle() > startPos - targetPos;
	}
}

// Called once after isFinished returns true
void AutoDriveTurn::End() {
	Robot::octaDrive.get()->Move(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveTurn::Interrupted() {
	End();
}
