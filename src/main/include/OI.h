#pragma once

#include <frc/WPILib.h>

class OI {
 private:
  std::shared_ptr<frc::Joystick> driverJoystick;
 public:
  std::shared_ptr<frc::Joystick> getDriverJoystick();
  OI();
};
