#pragma once

#include <frc/commands/Command.h>

class GrabberCommand : public frc::Command {
 private:
  double speed;
 public:
  GrabberCommand(double spd);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
