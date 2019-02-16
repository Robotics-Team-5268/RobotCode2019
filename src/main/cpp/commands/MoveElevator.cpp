#include "commands/MoveElevator.h"
#include "subsystems/Elevator.h"

MoveElevator::MoveElevator(double spd) : CommandBase("MoveElevator") {
  Requires(CommandBase::elevator.get());
  speed = spd;
}

void MoveElevator::Initialize() {
}

void MoveElevator::Execute() {
  CommandBase::elevator->MoveMotor(speed);
}

bool MoveElevator::IsFinished() {
  return true;
}

void MoveElevator::End() {
  CommandBase::elevator->MoveMotor(0.0);
}

void MoveElevator::Interrupted() {}
