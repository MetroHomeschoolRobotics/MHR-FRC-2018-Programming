/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoCenterLeft.h"

AutoCenterLeft::AutoCenterLeft() {
	AddSequential(new AutoDriveRotation(5000, 0,-0.3,0,FrontRight));
	AddSequential(new AutoDriveRotation(12500, -0.5,-0.4,0,FrontRight));

	AddSequential(new AutoDriveRotation(12500, 0,-0.3,0,FrontRight));
	AddSequential(new AutoDriveRotation(5500, 0.5,-0.4,0,FrontRight));
	AddSequential(new AutoDriveRotation(4500, 0,-0.3,0,FrontLeft));

	AddSequential(new ArmPreset(8000));
	AddSequential(new Drool());
}
