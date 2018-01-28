#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"
#include "Spark.h"

std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveFrontLeft;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveFrontRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveRearRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveRearLeft;

std::shared_ptr<frc::Spark> RobotMap::liftMotor;

std::shared_ptr<frc::DoubleSolenoid> RobotMap::octoDriveSwitchSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::liftGrabSol1;

void RobotMap::init() {

    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    tankDriveFrontLeft.reset(new WPI_TalonSRX(0));
    
    tankDriveFrontRight.reset(new WPI_TalonSRX(2));

    tankDriveRearRight.reset(new WPI_TalonSRX(3));

    tankDriveRearLeft.reset(new WPI_TalonSRX(1));

    liftMotor.reset(new frc::Spark(0));
    
    octoDriveSwitchSol1.reset(new frc::DoubleSolenoid(0, 0, 1));
    lw->AddActuator("OctaDrive", "SwitchSol1", octoDriveSwitchSol1);
    octoDriveSwitchSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
    
    liftGrabSol1.reset(new frc::DoubleSolenoid(0, 2, 3));
    lw->AddActuator("Lift", "SwitchSol2", liftGrabSol1);
    liftGrabSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);

}
