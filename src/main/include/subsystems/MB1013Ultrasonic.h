#pragma once

#include <frc/commands/Subsystem.h>

#include "RobotMap.h"

class MB1013Ultrasonic : public frc::Subsystem {
 private:
  frc::AnalogInput ultrasonic{ULTRASONIC};
 public:
  MB1013Ultrasonic();
  double getVoltage();
};

/*
.29-.30 = 1 ft
.41-.42 = 1-1/2 ft
.58-.60 = 2 ft
.72-.72 = 2-1/2 ft
.86-.87 = 3 ft
1.09-1.10 = 4 ft
*/