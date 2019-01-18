#pragma once

#include "CommandBase.h"

class VelocityTest : public CommandBase {
 public:
  VelocityTest();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:
  double driveCommand;
  int count;
};
