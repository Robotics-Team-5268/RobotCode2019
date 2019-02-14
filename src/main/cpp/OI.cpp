#include <frc/WPILib.h>
#include "OI.h"
#include "frc/smartDashboard/SmartDashboard.h"
#include "Robot.h"
#include "commands/DriveStraightDistance.h"

OI::OI() {
  driverJoystick.reset(new frc::Joystick(0));
  for (int i=1; i<=10; i++){
    driverBtns.push_back(new frc::JoystickButton(driverJoystick.get(), i));
  }
  driverBtns[1]->WhenPressed(new DriveStraightDistance(100));
}

std::shared_ptr<frc::Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
