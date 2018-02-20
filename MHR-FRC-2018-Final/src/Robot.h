//Define Class
#ifndef _ROBOT_H
#define _ROBOT_H

//Include Headers
#include "WPILib.h"

#include "LiveWindow/LiveWindow.h"

#include "OI.h"
#include "RobotMap.h"

#include "Commands/Command.h"

#include "Commands/AutoLeft.h"
#include "Commands/AutoCenter.h"
#include "Commands/AutoRight.h"
#include "Commands/Drive.h"
#include "Commands/Lift.h"
#include "Commands/Clamp.h"
#include "Subsystems/AutonomousSystem.h"

#include "Subsystems/MechDrive.h"
#include "Subsystems/TankDrive.h"
#include "Subsystems/OctaDrive.h"
#include "Subsystems/BoxLift.h"
#include "Subsystems/Positioning.h"
#include "Subsystems/PneumaticCharging.h"

class Robot : public frc::TimedRobot {

public:

	//Create Commands
	frc::Command* autonomousCommand = nullptr;
	frc::Command* driveCommand = nullptr;
	frc::Command* liftCommand = nullptr;
	frc::Command* clampCommand = nullptr;

	static std::unique_ptr<OI> oi;

	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	std::shared_ptr<frc::SendableChooser<frc::Command*>> chooser;

	//Create Shared Pointers
	static std::shared_ptr<TankDrive> tankDrive;
	static std::shared_ptr<MechDrive> mechDrive;
	static std::shared_ptr<OctaDrive> octaDrive;
	static std::shared_ptr<BoxLift> boxLift;
	static std::shared_ptr<Positioning> positioning;
	static std::shared_ptr<AutonomousSystem> autonomousSys;
	static std::shared_ptr<PneumaticCharging> pneumatics;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};

#endif
