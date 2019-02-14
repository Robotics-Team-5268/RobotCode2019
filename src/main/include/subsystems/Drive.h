#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Ultrasonic.h>

#include "RobotMap.h"

class Drive : public frc::Subsystem {
 private:
    frc::Talon speedControllerFL{DRIVE_SPEED_CONTROLLER_FL_CHANNEL};
	frc::Talon speedControllerBL{DRIVE_SPEED_CONTROLLER_BL_CHANNEL};
	frc::SpeedControllerGroup leftSC{speedControllerFL, speedControllerBL};

	frc::Talon speedControllerFR{DRIVE_SPEED_CONTROLLER_FR_CHANNEL};
	frc::Talon speedControllerBR{DRIVE_SPEED_CONTROLLER_BR_CHANNEL};
	frc::SpeedControllerGroup rightSC{speedControllerFR, speedControllerBR};

	frc::DifferentialDrive diffDrive{leftSC, rightSC};
	float oldLeftSpeed, oldRightSpeed;
	const float MAX_CHANGE = .05;
	const float MAX_SPEED = 3000;//used to be 3000
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