#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Counter.h>

#include "RobotMap.h"

class Arm : public frc::Subsystem {
 private:
  frc::Talon arm_SC{ARM_SPEED_CONTROLLER_CHANNEL};
  frc::Counter hallSensor{HALL_SENSOR};
 public:
  Arm();
  void MoveArm();
  int GetCount();
};
