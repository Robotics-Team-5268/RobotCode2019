#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Counter.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>

#include "RobotMap.h"

class Arm : public frc::Subsystem {
 private:
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX arm_SC{ARM_SPEED_CONTROLLER_CHANNEL};
  //frc::Counter hallSensor{HALL_SENSOR};
 public:
  Arm();
  void MoveArm(double speed);
  void InitDefaultCommand();
  //int GetCount();
};
