#include "subsystems/Elevator.h"
#include "CommandBase.h"
#include "commands/MoveElevator.h"



Elevator::Elevator() : Subsystem("Elevator")  {
    topLimitSwitch = new frc::DigitalInput(1);
    bottomLimitSwitch = new frc::DigitalInput(0);
}

void Elevator::InitDefaultCommand(){
    SetDefaultCommand(new MoveElevator());
}

void Elevator::MoveMotor(double speed) {
    elevator_SC.Set(-speed);
    //if the elevator is at the top
    /*
    if(topLimitSwitch->Get()){
        if(speed<=0){
            elevator_SC.Set(speed);
        }
        if(speed > 0){
            elevator_SC.Set(0);
        }
    }
    //if the elevator is at the bottom
    else if(bottomLimitSwitch->Get()){
        if(speed>=0){
            elevator_SC.Set(speed);
        }
        if(speed < 0){
            elevator_SC.Set(0);
        }
    }
    //if the elevator is somewhere in between
    else {
        elevator_SC.Set(speed);
    }
    */
    
}