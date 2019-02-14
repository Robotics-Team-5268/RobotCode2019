#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/drive/DifferentialDrive.h>

#include "RobotMap.h"

class Elevator : public frc::Subsystem{
 private:
  frc::Talon elevator_SC{ELEVATOR_SPEED_CONTROLLER_CHANNEL};
 
 public:
  Elevator();
  void InitDefaultCommand();
  void MoveMotor(double speed);
};