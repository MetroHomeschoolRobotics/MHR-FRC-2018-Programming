#ifndef BoxLift_H
#define BoxLift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

class BoxLift : public frc::Subsystem {

private:

	std::shared_ptr<WPI_TalonSRX> liftMotor;
	std::shared_ptr<frc::DoubleSolenoid> grabSol1;
	std::shared_ptr<frc::Encoder> liftEncoder;
	std::shared_ptr<Spark> corkscrewMotor;
	std::shared_ptr<Spark> intakeLeft;
	std::shared_ptr<Spark> intakeRight;
	std::shared_ptr<frc::DoubleSolenoid> pushSol1;
	std::shared_ptr<frc::DoubleSolenoid> pushSol2;

	double threshold = 0.1;
	bool isHold = false;
	bool inRangeOverride = false;
	double minLift = 23500;
	double maxLift = 0;
public:

	BoxLift();
	void InitDefaultCommand();
	void Rotate(double r);
	void Grab();
	void SetOverride(bool active);

    void EatBox(bool start);
    void PukeBox(bool start);
    void DroolBox();
    void ArmPreset(int position);

    void Eject();

    void Clamp(bool in);
    void Clamp(double speed);
    void ClampReset();

    int GetArmHeight();
};

#endif
