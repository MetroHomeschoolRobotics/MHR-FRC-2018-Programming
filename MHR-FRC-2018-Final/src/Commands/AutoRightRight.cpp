/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoRightRight.h"

AutoRightRight::AutoRightRight() {
	AddSequential(new AutoDriveRotation(2000, 0,-0.4,0,FrontLeft));
	AddSequential(new AutoDriveRotation(38000, 0,-0.6,0,FrontLeft));
	AddSequential(new SwitchDrive());
	AddSequential(new AutoDriveTurn(58, 0, 0, .4));
	AddSequential(new SwitchDrive());
	AddSequential(new AutoDriveRotation(6500, 0,-0.4,0,FrontLeft));
	AddSequential(new ArmPreset(8000));
	AddSequential(new Drool());
}
