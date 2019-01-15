#include <frc/WPILib.h>
#include "OI.h"
#include "frc/smartDashboard/SmartDashboard.h"
#include "Robot.h"

OI::OI() {
  driverJoystick.reset(new frc::Joystick(0));
}

std::shared_ptr<frc::Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
