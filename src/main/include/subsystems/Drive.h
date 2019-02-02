#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/drive/DifferentialDrive.h>

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
	float velocityToCommandIntercept[4];
	float velocityToCommandSlope[4]; 
 public:
  Drive();
  void InitDefaultCommand() override;
  virtual void setMotors(float leftSpeed, float rightSpeed);
  virtual void safetyOff() {diffDrive.SetSafetyEnabled(false);}
  virtual void takeInput();
  void setVelocity(float left, float right);
  void findVelocity(float left, float right);
};