#include "subsystems/Elevator.h"
#include "CommandBase.h"

Elevator::Elevator() : Subsystem("Elevator")  {

}

void Elevator::InitDefaultCommand(){

}

void Elevator::MoveMotor(double speed) {
    elevator_SC.Set(speed);
}