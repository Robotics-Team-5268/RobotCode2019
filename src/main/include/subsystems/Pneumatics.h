#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>

#include "RobotMap.h"

class Pneumatics : public frc::Subsystem {
 private:
  frc::Compressor compressor{PCM_PORT};
  frc::DoubleSolenoid doubleSolenoid{PCM_PORT, DOUBLESOLENOID_FORWARD_CHANNEL, DOUBLESOLENOID_REVERSE_CHANNEL};
 public:
  Pneumatics();
  void Forward();
  void Reverse();
  void Off();
};
