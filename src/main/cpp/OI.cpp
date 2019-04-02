#include <frc/WPILib.h>
#include <frc/DoubleSolenoid.h>
#include "OI.h"
#include "frc/smartDashboard/SmartDashboard.h"
#include "Robot.h"
#include "commands/DriveStraightDistance.h"
#include "commands/ArmCommand.h"
#include "commands/MoveElevator.h"
#include "commands/MovePneumatics.h"
#include "commands/GrabberCommand.h"
#include "commands/VenturiCommand.h"

OI::OI() {
  driverJoystick.reset(new frc::Joystick(0));
  mechanismsJoystick.reset(new frc::Joystick(1));
  for (int i=1; i<=10; i++){
    driverBtns.push_back(new frc::JoystickButton(driverJoystick.get(), i));
    mechanismsBtns.push_back(new frc::JoystickButton(mechanismsJoystick.get(), i));
  }
  //these buttons are for the logitech controller
  driverBtns[1]->WhenPressed(new DriveStraightDistance(36));//This should be the 'B' button on the logitech controller
  //these buttons are for the xbox controller
  
  /*//I think that the left joystick will control the elevator so this is unneeded and we can use the buttons elsewhere
  //if elevator suddenly doesn't work, comment out the limit switches stuff in elevator.cpp
  mechanismsBtns[0]->WhileHeld(new MoveElevator(-1.0)); //This should be 'a' button on the XBox controller
  mechanismsBtns[0]->WhenReleased(new MoveElevator(0.0)); //This should be 'a' button on the XBox controller
  mechanismsBtns[1]->WhileHeld(new MoveElevator(1.0)); //This should be 'b' button on the XBox controller
  mechanismsBtns[1]->WhenReleased(new MoveElevator(0.0)); //This should be 'b' button on the XBox controller
  */

  //this controls the Hatch Grab mechanism
  
  mechanismsBtns[0]->WhenPressed(new VenturiCommand(1)); //This should be 'A' button on the XBox controller
  mechanismsBtns[0]->WhenReleased(new VenturiCommand(2)); //This should be 'A' button on the XBox controller
  mechanismsBtns[1]->WhenPressed(new VenturiCommand(3)); //This should be 'B' button on the XBox controller
  
  //this controls the arm
  /*This done got removed
  mechanismsBtns[5]->WhileHeld(new ArmCommand(0.4)); //This should be 'RB' on the XBox controller
  mechanismsBtns[5]->WhenReleased(new ArmCommand(0.0)); //This should be 'RB' on the XBox controller
  mechanismsBtns[4]->WhileHeld(new ArmCommand(-0.4)); //This should be 'LB' on the XBox controller
  mechanismsBtns[4]->WhenReleased(new ArmCommand(0.0)); //This should be 'LB' on the XBox controller
  */

  //this controls the ball grab mechanism
  mechanismsBtns[2]->WhileHeld(new GrabberCommand(1.0)); //This should be the 'X' button on the xbox controller
  mechanismsBtns[2]->WhenReleased(new GrabberCommand(0.0)); //This should be the 'X' button on the xbox controller
  mechanismsBtns[3]->WhileHeld(new GrabberCommand(-1.0)); //This should be the 'Y' button on the xbox controller
  mechanismsBtns[3]->WhenReleased(new GrabberCommand(0.0)); //This should be the 'Y' button on the xbox controller

  //the elevator is controlled by the left joystick on the mechanism controller (xbox).
}

std::shared_ptr<frc::Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
std::shared_ptr<frc::Joystick> OI::getMechanismJoystick() {
	return mechanismsJoystick;
}
