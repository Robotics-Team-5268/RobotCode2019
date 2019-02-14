#pragma once

#include "CommandBase.h"

class LowerArm : public CommandBase {
 private:
  const int STOP_POINT = 25;
 public:
  LowerArm();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
