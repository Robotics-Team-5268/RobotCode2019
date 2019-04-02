#include "commands/ArmCommand.h"
#include "subsystems/Arm.h"
//This class has been inplemented to work exactly like elevator
ArmCommand::ArmCommand(double speed) {
  //Requires(CommandBase::arm.get());
  spd = speed;
}


void ArmCommand::Initialize() {}


void ArmCommand::Execute() {
  //CommandBase::arm->MoveArm(spd);
}


bool ArmCommand::IsFinished() { return true; }


void ArmCommand::End() {}

void ArmCommand::Interrupted() {}
