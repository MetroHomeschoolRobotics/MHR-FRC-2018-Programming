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
std::shared_ptr<Spark> RobotMap::corkscrewClampMotor;
std::shared_ptr<Spark> RobotMap::leftBoxIntake;
std::shared_ptr<Spark> RobotMap::rightBoxIntake;

std::shared_ptr<frc::DoubleSolenoid> RobotMap::octoDriveSwitchSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::liftGrabSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::pusherSol1;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::pusherSol2;

std::shared_ptr<frc::Encoder> RobotMap::liftMotorEncoder;

std::shared_ptr<LidarV3> RobotMap::lidarDistanceSensor;
std::shared_ptr<ADXRS450_Gyro> RobotMap::gyro;

std::shared_ptr<Compressor> RobotMap::pneumoCharger;
// For Ultrasonic: Devantech SRF04, VEX Ultrasonic Rangefinder
std::shared_ptr<Ultrasonic> RobotMap::ultrasonicDistanceSensor;
// For Ultrasonic: Maxbotix LV-MaxSonar-EZ1
std::shared_ptr<AnalogInput> RobotMap::ultrasonicAnalogDistanceSensor;
int RobotMap::UltrasonicAnalogPort = 0;


void RobotMap::init() {

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
    corkscrewClampMotor.reset(new Spark(2));
    
    lidarDistanceSensor.reset(new LidarV3(new DigitalInput(0)));
    // For Ultrasonic: Devantech SRF04, VEX Ultrasonic Rangefinder
    //ultrasonicDistanceSensor.reset(new Ultrasonic(1, 1));
    // For Ultrasonic: Maxbotix LV-MaxSonar-EZ1
    ultrasonicAnalogDistanceSensor.reset(new AnalogInput(UltrasonicAnalogPort));

    gyro.reset(new ADXRS450_Gyro());

    octoDriveSwitchSol1.reset(new frc::DoubleSolenoid(0, 0, 1));
    octoDriveSwitchSol1->Set(frc::DoubleSolenoid::kReverse);
    octoDriveSwitchSol1->SetName("OctoDrive", "SwitchSol1");
    octoDriveSwitchSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
    

    pusherSol1.reset(new frc::DoubleSolenoid(0, 2, 3));
    pusherSol1->SetName("Lift", "SwitchSol2");
    pusherSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);

    pusherSol2.reset(new frc::DoubleSolenoid(0, 4, 5));
    pusherSol2->SetName("Lift", "SwitchSol2");
    pusherSol2.get()->Set(frc::DoubleSolenoid::Value::kReverse);

    liftMotorEncoder.reset(new frc::Encoder(0, 1, false, Encoder::EncodingType::k4X));

    pneumoCharger.reset(new Compressor());
}
