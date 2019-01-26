#pragma once

#include "CommandBase.h"

#include <frc/PowerDistributionPanel.h>
#include <iostream>
#include <fstream>
#include <string>

class VelocityTest : public CommandBase {
 public:
  VelocityTest();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:
  frc::PowerDistributionPanel pdp;
  double driveCommand;
  int count;
  std::ofstream fout;
};
