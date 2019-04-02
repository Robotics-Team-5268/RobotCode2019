#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>

#include "RobotMap.h"

class Grabber : public frc::Subsystem {
 private:
  //frc::Talon speedControllerL{GRABBER_SPEED_CONTROLLER_L_CHANNEL};
	//frc::Talon speedControllerR{GRABBER_SPEED_CONTROLLER_R_CHANNEL};

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX speedControllerL{GRABBER_SPEED_CONTROLLER_L_CHANNEL};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX speedControllerR{GRABBER_SPEED_CONTROLLER_R_CHANNEL};
  //if you want to ungroup the speed controllers, comment out line 13
  frc::SpeedControllerGroup GrabberSCG{speedControllerL, speedControllerR};
 public:
  Grabber();
  void SetMotors(double speed);
};
