//Include Headers
#include "Robot.h"

//Instantiate Pointers
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<BoxLift> Robot::boxLift;
std::shared_ptr<TankDrive> Robot::tankDrive;
std::shared_ptr<MechDrive> Robot::mechDrive;
std::shared_ptr<OctaDrive> Robot::octaDrive;
std::shared_ptr<Positioning> Robot::positioning;

void Robot::RobotInit() {

	RobotMap::init();

	CameraServer::GetInstance()->StartAutomaticCapture();

	//Initialize Commands
	driveCommand = new Drive();
	liftCommand = new Lift();

	//Initialize Subsystems
	positioning.reset(new Positioning());

    tankDrive.reset(new TankDrive());
    mechDrive.reset(new MechDrive());
    octaDrive.reset(new OctaDrive());

    boxLift.reset(new BoxLift());

    //Instantiate OI
	oi.reset(new OI());

	chooser.AddDefault("Autonomous Command", new Auto());

	frc::SmartDashboard::PutData("Auto Modes", &chooser);
}

void Robot::DisabledInit(){

	//Disable Drive
	if (driveCommand != nullptr)
		driveCommand->Cancel();

}

void Robot::DisabledPeriodic() {

	frc::Scheduler::GetInstance()->Run();

}

void Robot::AutonomousInit() {

	//Initialize Autonomous
	autonomousCommand = chooser.GetSelected();

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

	if (driveCommand != nullptr)
		driveCommand->Start();

	if (liftCommand != nullptr)
		liftCommand->Start();

}

void Robot::TeleopPeriodic() {

	frc::Scheduler::GetInstance()->Run();

}

START_ROBOT_CLASS(Robot);

