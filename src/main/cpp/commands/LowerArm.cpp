#include "commands/LowerArm.h"

LowerArm::LowerArm() :CommandBase("LowerArm") {
  Requires(CommandBase::arm.get());
}

void LowerArm::Initialize() {}

void LowerArm::Execute() {
  CommandBase::arm->MoveArm();
}

bool LowerArm::IsFinished() {
  return CommandBase::arm->GetCount() <= STOP_POINT;
}

void LowerArm::End() {}

void LowerArm::Interrupted() {}
