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

	//Initialize Subsystems
	positioning.reset(new Positioning());

    tankDrive.reset(new TankDrive());
    mechDrive.reset(new MechDrive());
    octaDrive.reset(new OctaDrive());

    boxLift.reset(new BoxLift());
    autonomousSys.reset(new AutonomousSystem());

	//Initialize Commands
	driveCommand = new Drive();
	liftCommand = new Lift();
	clampCommand = new Clamp();


    //Instantiate OI
	oi.reset(new OI());
	oi.get()->SetupDashboard();
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

}

void Robot::AutonomousInit() {

	//Initialize Autonomous
	autonomousCommand = oi.get()->getAutoChooser()->GetSelected();

	if (autonomousCommand != nullptr)
		autonomousCommand->Start();

}

void Robot::AutonomousPeriodic() {
	UpdateDashboardStats();
	frc::Scheduler::GetInstance()->Run();

}

void Robot::TeleopInit() {

    frc::SmartDashboard::PutData("Autonomous Start", oi.get()->getAutoChooser());

	//Initialize Drive and Lift and Disable Auto
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();

	if (driveCommand != nullptr)
		driveCommand->Start();

	if (liftCommand != nullptr)
		liftCommand->Start();

	//if (clampCommand != nullptr)
	//	clampCommand->Start();
}

void Robot::TeleopPeriodic() {
	try {
		UpdateStatFile();
	} catch (int e){

	}
	UpdateDashboardStats();
	frc::Scheduler::GetInstance()->Run();
}

void Robot::UpdateDashboardStats() {
	SmartDashboard::PutNumber("Distance Sensor", positioning.get()->GetDistance());
	SmartDashboard::PutNumber("Gyro", positioning.get()->GetAngle());
	SmartDashboard::PutNumber("Front Left Distance", positioning.get()->GetFrontLeftDistance());
	SmartDashboard::PutNumber("Rear Left Distance", positioning.get()->GetRearLeftDistance());
	SmartDashboard::PutNumber("Front Right Distance", positioning.get()->GetFrontRightDistance());
	SmartDashboard::PutNumber("Rear Right Distance", positioning.get()->GetRearRightDistance());
	SmartDashboard::PutNumber("Arm Rotation", positioning.get()->GetArmRotation());

}

void Robot::UpdateStatFile() {
	ofstream statfile ("/home/lvuser/stats.txt");
	if (statfile.is_open())
	{

		statfile << "{";
		statfile << "\"Alliance\":" << m_ds.GetAlliance() << ",";
		statfile << "\"MatchType\":" << m_ds.GetMatchType() << ",";
		statfile << "\"MatchNumber\":" << m_ds.GetMatchNumber() << ",";
		statfile << "\"MatchTime\":" << m_ds.GetMatchTime() << ",";
		statfile << "\"IsBrownedOut\":" << (RobotController::IsBrownedOut() == true ? "true" : "false") << ",";
		try {
			statfile << "\"BatteryVoltage\":" << m_ds.GetBatteryVoltage() << ",";
		} catch (int e){

		}
		statfile << "\"GyroAngle\":" << positioning.get()->GetAngle() << ",";
		statfile << "\"Distance\":" << positioning.get()->GetDistance() << ",";
		statfile << "\"FrontLeft\":" << positioning.get()->GetFrontLeftDistance() << ",";
		statfile << "\"FrontRight\":" << positioning.get()->GetFrontRightDistance() << ",";
		statfile << "\"RearLeft\":" << positioning.get()->GetRearLeftDistance() << ",";
		statfile << "\"RearRight\":" << positioning.get()->GetRearRightDistance() << ",";
		if (octaDrive.get()->IsTankDrive()){
			statfile << "\"DriveMode\": \"Tank\"";
		} else {
			statfile << "\"DriveMode\": \"Mecanum\"";
		}
		statfile << "}";
		statfile.close();
	}
	else cout << "Unable to open file";
}



START_ROBOT_CLASS(Robot);

