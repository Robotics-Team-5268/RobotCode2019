#include "commands/MovePneumatics.h"
#include "CommandBase.h"

MovePneumatics::MovePneumatics(frc::DoubleSolenoid::Value v) : CommandBase("MovePneumatics") {
    Requires(CommandBase::pneumatics.get());
    value = v;
}

void MovePneumatics::Initialize() {}

void MovePneumatics::Execute() {
    if (value == frc::DoubleSolenoid::kForward) {
        CommandBase::pneumatics->Forward();
    } else if (value == frc::DoubleSolenoid::kReverse){
        CommandBase::pneumatics->Reverse();
    } else {
        CommandBase::pneumatics->Off();
    }
}

bool MovePneumatics::IsFinished() { 
    return true; 
}

void MovePneumatics::End() {}

void MovePneumatics::Interrupted() {}
