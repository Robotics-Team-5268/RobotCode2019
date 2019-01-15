#pragma once

#include "CommandBase.h"

class DriveWithJoystick : public CommandBase {
 public:
  DriveWithJoystick();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
