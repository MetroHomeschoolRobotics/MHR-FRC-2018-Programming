/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoLeftLeft.h"

AutoLeftLeft::AutoLeftLeft() {
	AddSequential(new AutoDriveRotation(2000, 0,-0.3,0,FrontLeft));
	AddSequential(new AutoDriveRotation(41000, 0,-0.5,0,FrontLeft));
	AddSequential(new SwitchDrive());
	AddSequential(new AutoDriveTurn(-60, 0, 0, -.4));
	AddSequential(new SwitchDrive());
	AddSequential(new AutoDriveRotation(9000, 0,-0.4,0,FrontLeft), 1);
	AddSequential(new ArmPreset(8000));
	AddSequential(new Drool());
}
