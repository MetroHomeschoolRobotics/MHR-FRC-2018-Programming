//Include Headers
#include "Robot.h"

//Instantiate Pointers
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<BoxLift> Robot::boxLift;
std::shared_ptr<TankDrive> Robot::tankDrive;
std::shared_ptr<MechDrive> Robot::mechDrive;
std::shared_ptr<OctaDrive> Robot::octaDrive;
std::shared_ptr<Positioning> Robot::positioning;
std::shared_ptr<AutonomousSystem> Robot::autonomousSys;
std::shared_ptr<PneumaticCharging> Robot::pneumatics;

void Robot::RobotInit() {

	RobotMap::init();

	cs::UsbCamera cam0 = CameraServer::GetInstance()->StartAutomaticCapture();
	cam0.SetFPS(30);
	cam0.SetResolution(640,480);

	pneumatics.reset(new PneumaticCharging());

	//Initialize Commands
	driveCommand = new Drive();
	liftCommand = new Lift();
	clampCommand = new Clamp();

	//Initialize Subsystems
	positioning.reset(new Positioning());

    tankDrive.reset(new TankDrive());
    mechDrive.reset(new MechDrive());
    octaDrive.reset(new OctaDrive());

    boxLift.reset(new BoxLift());

    autonomousSys.reset(new AutonomousSystem(octaDrive.get(), boxLift.get(), positioning.get()));

    //Instantiate OI

	oi.reset(new OI());
	//chooser = oi.get()->getAutoChooser();
	chooser.reset(new frc::SendableChooser<frc::Command*>());
	chooser.get()->AddObject("Start Left", new AutoLeft());
	chooser.get()->AddDefault("Start Center", new AutoCenter());
	chooser.get()->AddObject("Start Right", new AutoRight());

	frc::SmartDashboard::PutData("Auto Modes", chooser.get());

}

void Robot::DisabledInit(){

	//Disable Drive
	if (driveCommand != nullptr)
		driveCommand->Cancel();

}

void Robot::DisabledPeriodic() {

	frc::Scheduler::GetInstance()->Run();
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();

	autonomousSys->Complete();
}

void Robot::AutonomousInit() {

	//Initialize Autonomous
	autonomousCommand = chooser.get()->GetSelected();

	if (autonomousCommand != nullptr)
		autonomousCommand->Start();

}

void Robot::AutonomousPeriodic() {

	frc::Scheduler::GetInstance()->Run();

}

void Robot::TeleopInit() {

	//Initialize Drive and Lift and Disable Auto
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
	autonomousSys->Complete();

	if (driveCommand != nullptr)
		driveCommand->Start();

	if (liftCommand != nullptr)
		liftCommand->Start();

	//if (clampCommand != nullptr)
	//	clampCommand->Start();
}

void Robot::TeleopPeriodic() {

	frc::Scheduler::GetInstance()->Run();

}

START_ROBOT_CLASS(Robot);

