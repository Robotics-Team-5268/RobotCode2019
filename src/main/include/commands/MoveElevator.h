#pragma once

#include "CommandBase.h"

class MoveElevator : public CommandBase {
 private:
 public:
  MoveElevator();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
