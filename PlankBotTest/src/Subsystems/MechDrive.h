// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef MECHDRIVE_H
#define MECHDRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class MechDrive: public frc::Subsystem {
private:
	std::shared_ptr<WPI_TalonSRX> frontLeft;
	std::shared_ptr<WPI_TalonSRX> frontRight;
	std::shared_ptr<WPI_TalonSRX> rearRight;
	std::shared_ptr<WPI_TalonSRX> rearLeft;
	double threshold = 0.1;
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	MechDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y, double z);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
