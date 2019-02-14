#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Compressor.h>
#include <frc/Solenoid.h>

#include "RobotMap.h"

class Pneumatics : public frc::Subsystem {
 private:
  frc::Compressor compressor{PCM_PORT};
  frc::Solenoid solenoid{SOLENOID_PORT};
 public:
  Pneumatics();
};
