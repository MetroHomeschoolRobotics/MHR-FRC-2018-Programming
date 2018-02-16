#include "BoxLift.h"
#include "../RobotMap.h"
#include <cmath>

BoxLift::BoxLift() : frc::Subsystem("BoxLift") {

	liftMotor = RobotMap::liftMotor;
	grabSol1 = RobotMap::liftGrabSol1;
	liftEncoder = RobotMap::liftMotorEncoder;
	corkscrewMotor = RobotMap::corkscrewClampMotor;
	intakeLeft = RobotMap::leftBoxIntake;
	intakeRight = RobotMap::rightBoxIntake;
}

void BoxLift::InitDefaultCommand() {
}

void BoxLift::SetOverride(bool active){

	if (active) {

		inRangeOverride = true;

	} else {

		inRangeOverride = false;
		liftMotor.get()->SetSelectedSensorPosition(0,0,5);

	}

}

void BoxLift::Rotate(double r){

	//Sets Threshold
	if(fabs(r) < threshold) {
			r = 0;
	}

	//Grabs Encoder Values as Integer "count"
	int count = liftMotor.get()->GetSelectedSensorPosition(0);


	//Divides Speed by Two
	//r /= 2;
	r = -r;
	// override to be always on
	if (true || inRangeOverride) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Restricts Movement Between Encoder Values
	} else if (count > -3500 && count < 0) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Allows Up Movement Into Range
	} else if (count < -3500 && r < 0) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Allows Down Movement Into Range
	} else if (count >= -50 && r > 0) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Sets Speed to Zero If Outside Range
	} else {

		//Sets Motor Speed
		liftMotor.get()->Set(0.0);

	}

	SmartDashboard::PutNumber("Rotation Count", count);

}

void BoxLift::Grab(){

	isHold = !isHold;

	if (isHold){
		grabSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
	} else {
		grabSol1.get()->Set(frc::DoubleSolenoid::Value::kForward);
	}

}

void BoxLift::EatBox(bool start){
	if (start){
		intakeLeft.get()->Set(-1);
		intakeRight.get()->Set(1);
	}else{
		intakeLeft.get()->Set(0);
		intakeRight.get()->Set(0);
	}
}

void BoxLift::PukeBox(bool start){
	if (start){
		intakeLeft.get()->Set(1);
		intakeRight.get()->Set(-1);
	}else{
		intakeLeft.get()->Set(0);
		intakeRight.get()->Set(0);
	}
}

void BoxLift::Clamp(bool in){
	if (in){
		corkscrewMotor.get()->Set(.3);
	} else {
		corkscrewMotor.get()->Set(-.3);
	}
}


void BoxLift::ClampReset() {
	corkscrewMotor.get()->Set(0);
}

void BoxLift::Clamp(double speed){
	intakeLeft.get()->Set(speed);
	intakeRight.get()->Set(-speed);
}
