#include "WPILib.h"
#include "CANTalon.h"
#include "Spark.h"

class Robot : public IterativeRobot
{
	//Construct for objects here
	Joystick *driveStick;
	Joystick *manipulatorStick;
	CANTalon *leftDrive1;
	CANTalon *leftDrive2;
	CANTalon *rightDrive1;
	CANTalon *rightDrive2;
	CANTalon *climber;
	//Spark *climber;
	DoubleSolenoid *gearCatch;

	// auto select start
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
	// auto select end

public:
	Robot() {
		Wait(1);
		driveStick = new Joystick (0);
		manipulatorStick = new Joystick (1);
		leftDrive1 = new CANTalon(1);
		leftDrive2= new CANTalon(2);
		rightDrive1 = new CANTalon(3);
		rightDrive2 = new CANTalon(4);
		climber = new CANTalon(5);
		gearCatch = new DoubleSolenoid(0,1);
	}

private:
		LiveWindow *lw = LiveWindow::GetInstance();

		// Auto Select Start

		// end of Auto Select

		double leftX = 0;
		double leftY = 0;
		double rightX = 0;
		double rightY = 0;
		double mLeftY = 0;
		double mRightY = 0;
		double leftTrigger = 0;
		double rightTrigger = 0;
		double mRightTrigger = 0;
		double mLeftTrigger = 0;
		bool dUp = false;
		bool dRight = false;
		bool dDown = false;
		bool dLeft = false;
		bool dUpR = false;
		bool dUpL = false;
		bool dDownR = false;
		bool dDownL = false;
		bool autoShot = false;
		bool buttonVal0 = false;
		bool buttonVal1 = false;
		bool buttonVal2 = false;
		bool buttonVal3 = false;
		double threshold = 0.09;

		//vision tracking
	/*	double IMAGE_WIDTH = 320;
		double IMAGE_HEIGHT = 240;
		int camWidth = 320;
		int camHeight = 240;
		std::shared_ptr<NetworkTable> roboRealm;
		cs::UsbCamera cam1;

	void RobotInit () override
	{
		roboRealm = NetworkTable::GetTable("cam1");

		cam1 = CameraServer::GetInstance()->StartAutomaticCapture("cam1",0);
		cam1.SetResolution(camWidth, camHeight);
		cam1.SetFPS(24);
	}
	*/

	/*
	 * Below is the code for auto selection to add an auto program
	 * continue with the else if statements
	 * remember to set auto to 0 for all actuators being user
	 * this will run when auto is enabled to be prepared to disable
	 * Make it known that you are testing
	 */
	void AutonomousInit() // code for auto mode !!!this will run and stop only when disabled!!!
	{
		{
			leftDrive1->Set(0.2);
			leftDrive2->Set(0.2);
			rightDrive1->Set(-0.23);
			rightDrive2->Set(-0.23);
			Wait(3);
			leftDrive1->Set(0);
			leftDrive2->Set(0);
			rightDrive1->Set(0);
			rightDrive2->Set(0);
		}
	}

	void TeleopInit() // holds code for pre teleop enable
	{

	}

	void TeleopPeriodic() // code for the robot to move is placed here (runs when
	// the robot is enabled in teleop mode)
	{
		//code for controller values

				leftX = driveStick->GetRawAxis(0);
				if(fabs(leftX) < threshold)
					leftX = 0;

				leftY = driveStick->GetRawAxis(1);
				if(fabs(leftY) < threshold)
					leftY = 0;

				mLeftY = manipulatorStick->GetRawAxis(1);
				if(fabs(mLeftY) < threshold)
					mLeftY = 0;

				rightX = driveStick->GetRawAxis(4);
				if(fabs(rightX) < threshold)
					rightX = 0;

				rightY = driveStick->GetRawAxis(5);
				if(fabs(rightY) < threshold)
					rightY = 0;

				mRightY = manipulatorStick->GetRawAxis(5);
				if(fabs(mRightY) < threshold)
					mRightY = 0;

				leftTrigger = (driveStick->GetRawAxis(2));
				if(fabs(leftTrigger) < (threshold))
					leftTrigger = 0;

				rightTrigger = (driveStick->GetRawAxis(3));
				if(fabs(rightTrigger) < (threshold))
					rightTrigger = 0;

				mRightTrigger = (manipulatorStick->GetRawAxis(3));
				if(fabs(mRightTrigger) < (threshold))
					mRightTrigger = 0;

				mLeftTrigger = (manipulatorStick->GetRawAxis(2));
				if(fabs(mLeftTrigger) < (threshold))
					mLeftTrigger = 0;

				leftX = pow(fabs(leftX), 1.4);
				if(driveStick->GetRawAxis(0) > 0) {
					leftX = -leftX;
				}

				leftY = pow(fabs(leftY), 1.4);
				if(driveStick->GetRawAxis(1) < 0) {
					leftY = -leftY;
				}

				rightX = pow(fabs(rightX), 1.4);
				if(driveStick->GetRawAxis(4) > 0) {
					rightX = -rightX;
				}

				rightY = pow(fabs(rightY), 1.4);
				if(driveStick->GetRawAxis(5) > 0) {
					rightY = -rightY;
				}

				mRightY = pow(fabs(mRightY), 1.4);
				if(manipulatorStick->GetRawAxis(5) > 0) {
					mRightY = -mRightY;
				}

				mLeftY = pow(fabs(mLeftY), 1.4);
				if(manipulatorStick->GetRawAxis(1) > 0) {
					mLeftY = -mLeftY;
				}
		// End of code for controller values

				    // drive code
					leftDrive1->Set(-leftY - leftX);
					leftDrive2->Set(-leftY - leftX);
					rightDrive1->Set(leftY - leftX);
					rightDrive2->Set(leftY - leftX);
				    // end of drive code

					// climb code start
					if (driveStick->GetRawAxis(2))
					{
						climber->Set(leftTrigger);
					}
					/*else if (driveStick->GetRawButton(5))
					{
						climber->Set(-0.5);
					}*/
					else
					{
						climber->Set(0);
					}
					// climb code end

					// gear catch start
					if(driveStick->GetRawButton(4))
					{
						gearCatch->Set(DoubleSolenoid::Value::kForward);
					}
					else if (driveStick->GetRawButton(1))
					{
						gearCatch->Set(DoubleSolenoid::Value::kReverse);
					}
					// gear catch code end

					leftDrive2.SetFeedbackDevice(CANTalon::QuadEncoder);
					
	}

	void TestInit()
	{

	}

	void TestPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
