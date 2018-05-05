/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoDriveDistance.h"

AutoDriveDistance::AutoDriveDistance(double distance, double driveX, double driveY, double driveZ) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::octaDrive.get());
	startPos = 0;
	targetPos = distance;
	x = driveX;
	y = driveY;
	z = driveZ;
}

// Called just before this Command runs the first time
void AutoDriveDistance::Initialize() {
	startPos = Robot::positioning.get()->GetDistance();
	Robot::octaDrive.get()->Move(x, y, z);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveDistance::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveDistance::IsFinished() {
	if (targetPos > 0) {
		return Robot::positioning.get()->GetDistance() > targetPos;
	} else {
		return Robot::positioning.get()->GetDistance() > startPos + targetPos;
	}
}

// Called once after isFinished returns true
void AutoDriveDistance::End() {
	Robot::octaDrive.get()->Move(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveDistance::Interrupted() {
	End();
}
