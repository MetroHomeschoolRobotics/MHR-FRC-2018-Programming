// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveFrontLeft;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveFrontRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveRearRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveRearLeft;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::octoDriveSwitchSol1;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    tankDriveFrontLeft.reset(new WPI_TalonSRX(0));
    
    
    tankDriveFrontRight.reset(new WPI_TalonSRX(1));
    
    
    tankDriveRearRight.reset(new WPI_TalonSRX(2));
    
    
    tankDriveRearLeft.reset(new WPI_TalonSRX(3));
    
    
    octoDriveSwitchSol1.reset(new frc::DoubleSolenoid(0, 0, 1));
    lw->AddActuator("OctoDrive", "SwitchSol1", octoDriveSwitchSol1);
    

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
