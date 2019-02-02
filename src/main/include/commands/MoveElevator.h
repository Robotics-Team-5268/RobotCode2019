#pragma once

#include "CommandBase.h"

class MoveElevator : public CommandBase {
 public:
  MoveElevator();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
