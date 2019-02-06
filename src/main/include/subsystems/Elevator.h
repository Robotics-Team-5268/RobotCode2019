#pragma once

#include <frc/commands/PIDSubsystem.h>
#include <frc/drive/DifferentialDrive.h>

#include "RobotMap.h"

class Elevator : public frc::PIDSubsystem{
 private:
  frc::Talon elevator_SC{ELEVATOR_SPEED_CONTROLLER_CHANNEL};
 
 public:
  Elevator();
  double ReturnPIDInput();
  void UsePIDOutput(double output);
  void InitDefaultCommand();
};