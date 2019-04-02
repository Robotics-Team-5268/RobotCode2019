#pragma once

#include "CommandBase.h"

class VenturiCommand : public frc::Command {
 public:
  VenturiCommand(int action);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
  int Action;
};
