#include "commands/MoveElevator.h"
#include "subsystems/Elevator.h"
//This is an example of the command that works, use this to model other commands for not working functionality
MoveElevator::MoveElevator() : CommandBase("MoveElevator") {
  Requires(CommandBase::elevator.get());
  //speed = spd;
}

void MoveElevator::Initialize() {
}

void MoveElevator::Execute() {
  //controls the elevator based on the parameter given to the command, this is what we will use if the line below this does not work
  //CommandBase::elevator->MoveMotor(speed);
  //controls the elevator based on the up and down position of the mechanism joystick (xbox controller)
  CommandBase::elevator->MoveMotor(CommandBase::oi->getMechanismJoystick()->GetRawAxis(1));
}

bool MoveElevator::IsFinished() {
  return true;
}

void MoveElevator::End() {
  
}

void MoveElevator::Interrupted() {}
