/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftRight.h"

AutoLeftRight::AutoLeftRight() {
	AddSequential(new AutoDriveDistance(100, 0, -0.65, 0));
	AddSequential(new AutoDriveTurn(85, 0, 0, .5));
	AddSequential(new SwitchDrive());
	AddSequential(new AutoDrive(0.5, 0, 0), 2.8);
	AddSequential(new AutoDrive(0, -0.5, 0), 2.65);
	AddSequential(new AutoDriveTurn(-85, 0, 0, -.5));
	AddSequential(new SwitchDrive());
	AddSequential(new AutoDrive(0.5, 0, 0), 1.75);
	AddSequential(new AutoDriveTurn(85, 0, 0, .5));
	AddSequential(new AutoDrive(0, -0.5, 0), 0.5);
	AddSequential(new ArmPreset(5500));
	AddSequential(new Drool());
}
