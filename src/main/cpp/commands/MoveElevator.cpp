#include "commands/MoveElevator.h"
#include "subsystems/Elevator.h"

MoveElevator::MoveElevator(double setpoint) : CommandBase("MoveElevator") {
  Requires(CommandBase::elevator.get());
  setPoint = setpoint;
}

void MoveElevator::Initialize() {
  CommandBase::elevator->SetSetpoint(setPoint);
  CommandBase::elevator->Enable();
}

void MoveElevator::Execute() {

}

bool MoveElevator::IsFinished() {
  return CommandBase::elevator->OnTarget(); 
}

void MoveElevator::End() {}

void MoveElevator::Interrupted() {}
