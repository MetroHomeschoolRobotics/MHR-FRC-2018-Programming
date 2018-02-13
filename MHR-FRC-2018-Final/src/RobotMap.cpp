#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"
#include "Spark.h"
#include "LidarV3.h"

std::shared_ptr<MecanumDrive> RobotMap::mainDrive;
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

    SpeedController *fLeft = tankDriveFrontLeft.get();
    SpeedController *rLeft = tankDriveRearLeft.get();
    SpeedController *fRight = tankDriveFrontRight.get();
    SpeedController *rRight = tankDriveRearRight.get();
    mainDrive.reset(new MecanumDrive(*fLeft, *rLeft, *rRight, *fRight));

    liftMotor.reset(new WPI_TalonSRX(4));
    leftBoxIntake.reset(new Spark(0));
    rightBoxIntake.reset(new Spark(1));
    
    lidarDistanceSensor.reset(new LidarV3(new DigitalInput(0)));

    gyro.reset(new AnalogGyro(0));

    octoDriveSwitchSol1.reset(new frc::DoubleSolenoid(0, 0, 1));
    octoDriveSwitchSol1->Set(frc::DoubleSolenoid::kReverse);
    octoDriveSwitchSol1->SetName("OctoDrive", "SwitchSol1");
    octoDriveSwitchSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
    
    liftGrabSol1.reset(new frc::DoubleSolenoid(0, 2, 3));
    liftGrabSol1->SetName("Lift", "SwitchSol2");
    liftGrabSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);

    liftMotorEncoder.reset(new frc::Encoder(0, 1, false, Encoder::EncodingType::k4X));

}
