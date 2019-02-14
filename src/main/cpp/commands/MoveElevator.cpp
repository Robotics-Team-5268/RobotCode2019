#include "commands/MoveElevator.h"
#include "subsystems/Elevator.h"

MoveElevator::MoveElevator() : CommandBase("MoveElevator") {
  Requires(CommandBase::elevator.get());
}

void MoveElevator::Initialize() {
}

void MoveElevator::Execute() {
  CommandBase::elevator->MoveMotor(0.6);
}

bool MoveElevator::IsFinished() {
  return true;
}

void MoveElevator::End() {
  CommandBase::elevator->MoveMotor(0.0);
}

void MoveElevator::Interrupted() {}
