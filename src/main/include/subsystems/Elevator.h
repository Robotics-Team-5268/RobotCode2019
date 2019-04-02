#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include "frc/WPILib.h"
#include "RobotMap.h"

class Elevator : public frc::Subsystem{
 private:
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX elevator_SC{ELEVATOR_SPEED_CONTROLLER_CHANNEL};
  frc::DigitalInput* topLimitSwitch;
  frc::DigitalInput* bottomLimitSwitch;
 public:
  Elevator();
  void InitDefaultCommand();
  void MoveMotor(double speed);
};