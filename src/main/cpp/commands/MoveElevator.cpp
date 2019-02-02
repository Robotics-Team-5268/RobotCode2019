#include "commands/MoveElevator.h"
#include "subsystems/Elevator.h"

MoveElevator::MoveElevator() : CommandBase("MoveElevator") {

}

void MoveElevator::Initialize() {

}

void MoveElevator::Execute() {}

bool MoveElevator::IsFinished() { 
  return false; 
}

void MoveElevator::End() {}

void MoveElevator::Interrupted() {}
