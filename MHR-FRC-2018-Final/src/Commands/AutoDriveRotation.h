/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include "../Robot.h"

enum DriveMotorEncoder {
		FrontLeft,
		FrontRight,
		RearLeft,
		RearRight
	};

class AutoDriveRotation : public frc::Command {
public:
	AutoDriveRotation(double rotation, double driveX, double driveY, double driveZ, DriveMotorEncoder encoder);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	double startPos, targetPos;
	double x, y, z;
	DriveMotorEncoder encoderSource;
	double GetEncoderValue();
};


