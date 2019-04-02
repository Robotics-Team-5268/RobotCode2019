#pragma once

#include "frc/WPILib.h"

class OI {
 private:
  std::shared_ptr<frc::Joystick> driverJoystick, mechanismsJoystick;
  std::vector<frc::JoystickButton*> driverBtns, mechanismsBtns;
 public:
  std::shared_ptr<frc::Joystick> getDriverJoystick();
  std::shared_ptr<frc::Joystick> getMechanismJoystick();
  OI();
};
