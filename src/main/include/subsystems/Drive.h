#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Ultrasonic.h>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>


#include "RobotMap.h"

class Drive : public frc::Subsystem {
 private:
	
	ctre::phoenix::motorcontrol::can::WPI_TalonSRX talonSRXFL{DRIVE_SPEED_CONTROLLER_FL_CHANNEL};
	ctre::phoenix::motorcontrol::can::WPI_TalonSRX talonSRXBL{DRIVE_SPEED_CONTROLLER_BL_CHANNEL};
	frc::SpeedControllerGroup leftSRXGroup{talonSRXFL, talonSRXBL};

	ctre::phoenix::motorcontrol::can::WPI_TalonSRX talonSRXFR{DRIVE_SPEED_CONTROLLER_FR_CHANNEL};
	ctre::phoenix::motorcontrol::can::WPI_TalonSRX talonSRXBR{DRIVE_SPEED_CONTROLLER_BR_CHANNEL};
	frc::SpeedControllerGroup rightSRXGroup{talonSRXFR, talonSRXBR};
	

	/* test chassis stuff
    frc::Talon speedControllerFL{DRIVE_SPEED_CONTROLLER_FL_CHANNEL};
	frc::Talon speedControllerBL{DRIVE_SPEED_CONTROLLER_BL_CHANNEL};
	frc::SpeedControllerGroup leftSC{speedControllerFL, speedControllerBL};
	frc::Talon speedControllerFR{DRIVE_SPEED_CONTROLLER_FR_CHANNEL};
	frc::Talon speedControllerBR{DRIVE_SPEED_CONTROLLER_BR_CHANNEL};
	frc::SpeedControllerGroup rightSC{speedControllerFR, speedControllerBR};

	frc::DifferentialDrive diffDrive{leftSC, rightSC}; //this line is used for the test chassis. It uses the Talon groups
	*/
	frc::DifferentialDrive diffDrive{leftSRXGroup, rightSRXGroup}; //this line is used for the 2019 robot. it uses the Talon SRX groups
	float oldLeftSpeed, oldRightSpeed;
	const float MAX_CHANGE = .05;
	const float MAX_SPEED = 3000;
	float velocityToCommandSlope[4];
	float velocityToCommandIntercept[4];

	frc::AnalogGyro gyro{GYRO_ANALOG_PORT};
 	


    //std::ofstream fout;
 public:
	Drive();
	void InitDefaultCommand() override;
	virtual void setMotors(float leftSpeed, float rightSpeed);
	virtual void safetyOff() {diffDrive.SetSafetyEnabled(false);}
	virtual void takeInput();
	frc::AnalogGyro* getGyro();
	float getGyroAngle();
	float getGyroRate();
	void resetGyro();
	void calibrateGyro();
	void SetVelocity(float left, float right);
};