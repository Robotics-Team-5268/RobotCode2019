#include <frc/WPILib.h>
#include <frc/DoubleSolenoid.h>
#include "OI.h"
#include "frc/smartDashboard/SmartDashboard.h"
#include "Robot.h"
#include "commands/DriveStraightDistance.h"
#include "commands/LowerArm.h"
#include "commands/MoveElevator.h"
#include "commands/MovePneumatics.h"

OI::OI() {
  driverJoystick.reset(new frc::Joystick(0));
  mechanismsJoystick.reset(new frc::Joystick(1));
  for (int i=1; i<=10; i++){
    driverBtns.push_back(new frc::JoystickButton(driverJoystick.get(), i));
    mechanismsBtns.push_back(new frc::JoystickButton(mechanismsJoystick.get(), i));
  }
  driverBtns[1]->WhenPressed(new DriveStraightDistance(100));
  mechanismsBtns[1]->WhileHeld(new MoveElevator(0.6)); //This should be 'b' button on the XBox controller
  mechanismsBtns[0]->WhileHeld(new MoveElevator(-0.6)); //This should be 'a' button on the XBox controller
  mechanismsBtns[2]->WhileHeld(new MovePneumatics(frc::DoubleSolenoid::kForward)); //This should be 'x' button on the XBox controller
  mechanismsBtns[2]->WhenReleased(new MovePneumatics(frc::DoubleSolenoid::kOff)); //This should be 'x' button on the XBox controller
  mechanismsBtns[3]->WhileHeld(new MovePneumatics(frc::DoubleSolenoid::kReverse)); //This should be 'y' button on the XBox controller
  mechanismsBtns[3]->WhenReleased(new MovePneumatics(frc::DoubleSolenoid::kOff)); //This should be 'y' button on the XBox controller
  mechanismsBtns[5]->WhenPressed(new LowerArm()); //Ths should be 'RB' on the XBox controller
}

std::shared_ptr<frc::Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
