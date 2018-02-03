#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"
#include "Spark.h"
#include "LidarV3.h"

std:shared_ptr<RobotDrive> RobotMap::mainDrive;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveFrontLeft;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveFrontRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveRearRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::tankDriveRearLeft;

std::shared_ptr<WPI_TalonSRX> RobotMap::liftMotor;

std::shared_ptr<frc::DoubleSolenoid> RobotMap::octoDriveSwitchSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::liftGrabSol1;

std::shared_ptr<frc::Encoder> RobotMap::liftMotorEncoder;

std::shared_ptr<LidarV3> RobotMap::lidarDistanceSensor;
std::shared_ptr<AnalogGyro> RobotMap::gyro;

void RobotMap::init() {

    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    tankDriveFrontLeft.reset(new WPI_TalonSRX(0));
    
    tankDriveFrontRight.reset(new WPI_TalonSRX(2));

    tankDriveRearRight.reset(new WPI_TalonSRX(3));

    tankDriveRearLeft.reset(new WPI_TalonSRX(1));

    mainDrive.reset(new RobotDrive(tankDriveFrontLeft.get(), tankDriveRearLeft.get(), tankDriveFrontRight.get(), tankDriveRearRight.get()));

    liftMotor.reset(new WPI_TalonSRX(4));
    
    lidarDistanceSensor.reset(new LidarV3(new DigitalInput(0)));

    gyro.reset(new AnalogGyro(1));

    octoDriveSwitchSol1.reset(new frc::DoubleSolenoid(0, 0, 1));
    octoDriveSwitchSol1->Set(frc::DoubleSolenoid::kReverse);
    lw->AddActuator("OctaDrive", "SwitchSol1", octoDriveSwitchSol1);
    octoDriveSwitchSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
    
    liftGrabSol1.reset(new frc::DoubleSolenoid(0, 2, 3));
    lw->AddActuator("Lift", "SwitchSol2", liftGrabSol1);
    liftGrabSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);

    liftMotorEncoder.reset(new frc::Encoder(0, 1, false, Encoder::EncodingType::k4X));

}
