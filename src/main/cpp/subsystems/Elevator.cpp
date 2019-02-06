#include "subsystems/Elevator.h"
#include "CommandBase.h"

Elevator::Elevator() : PIDSubsystem("Elevator", .05, .1, 0.0)  {
    GetPIDController()->SetContinuous(false);
    SetOutputRange(-1.0,1.0);
    SetAbsoluteTolerance(0.005);
}
double Elevator::ReturnPIDInput(){
    //return CommandBase::elevatorEncoder->PIDGet();
}
void Elevator::UsePIDOutput(double output){
    elevator_SC.Set(output);
}
void Elevator::InitDefaultCommand(){

}