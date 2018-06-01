#include "BoxLift.h"
#include "../RobotMap.h"
#include <cmath>

BoxLift::BoxLift() : frc::Subsystem("BoxLift") {
	liftEncoder = RobotMap::liftEncoder;
	liftRotationCounter = RobotMap::liftRotationCounter;
	liftMotor = RobotMap::liftMotor;
	grabSol1 = RobotMap::liftGrabSol1;
	pushSol1 = RobotMap::pusherSol1;
	pushSol2 = RobotMap::pusherSol2;
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
		RobotMap::gyro.get()->Reset();
	}

}

int BoxLift::GetArmHeight() {
	return liftMotor.get()->GetSelectedSensorPosition(0);
	//return liftEncoder.get()->GetDistance();
	//return liftRotationCounter.get()->Get();
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
	//r = -r;
	//Override to be always on
	if (inRangeOverride) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Restricts Movement Between Encoder Values
	} else if (count < minLift && count > maxLift) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Allows Up Movement Into Range
	} else if (count > minLift && r > 0) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Allows Down Movement Into Range
	} else if (count < maxLift + 50 && r < 0) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Sets Speed to Zero If Outside Range
	} else {

		//Sets Motor Speed
		liftMotor.get()->Set(0.0);

	}
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
		intakeLeft.get()->Set(.5);
		intakeRight.get()->Set(-.5);
}else{
		intakeLeft.get()->Set(0);
		intakeRight.get()->Set(0);
	}
}

void BoxLift::PukeBox(bool start){
	if (start){
		intakeLeft.get()->Set(.5);
		intakeRight.get()->Set(-.5);

		pushSol1.get()->Set(frc::DoubleSolenoid::Value::kForward);
		pushSol2.get()->Set(frc::DoubleSolenoid::Value::kForward);
		Wait(0.1);

		intakeLeft.get()->Set(-1);
		intakeRight.get()->Set(1);

		Wait(0.3);
		pushSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
		pushSol2.get()->Set(frc::DoubleSolenoid::Value::kReverse);
	//Spin the wheels
	//open the grabber
	//Activate the pusher
	//Do this all in less than a second

	}else{
		intakeLeft.get()->Set(0);
		intakeRight.get()->Set(0);
	}
}

void BoxLift::DroolBox(){
	intakeLeft.get()->Set(-.6);
	intakeRight.get()->Set(.6);

	Wait(.6);

	intakeLeft.get()->Set(0);
	intakeRight.get()->Set(0);

}

void BoxLift::Eject(){
	pushSol1.get()->Set(frc::DoubleSolenoid::Value::kForward);
	pushSol2.get()->Set(frc::DoubleSolenoid::Value::kForward);
	Wait(0.1);
	pushSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
	pushSol2.get()->Set(frc::DoubleSolenoid::Value::kReverse);
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

