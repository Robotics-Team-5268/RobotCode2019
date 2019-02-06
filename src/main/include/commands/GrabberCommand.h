#pragma once

#include <frc/commands/Command.h>

class GrabberCommand : public frc::Command {
 private:
  std::string direction;
 public:
  GrabberCommand(std::string drct);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
