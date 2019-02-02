#pragma once

#include <frc/commands/PIDSubsystem.h>
#include <frc/drive/DifferentialDrive.h>

#include "RobotMap.h"

class Elevator : public frc::PIDSubsystem{
 private:
  frc::Talon speedController{ELEVATOR_SPEED_CONTROLLER_CHANNEL};
 public:
  Elevator();
  void setMotor(double height);
};