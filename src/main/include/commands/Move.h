#pragma once

#include <frc/commands/Command.h>
#include <frc/Timer.h>
#include <frc/WPILib.h>

#include "CommandBase.h"

class Move : public CommandBase {
 public:
  Move(float tm, float spd);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
  float speed;
  float seconds;
  std::shared_ptr<frc::Timer> timer;
  frc::PIDController* pid;
};

class MovePIDOutput: public frc::PIDOutput {
  public:
    MovePIDOutput(double sp);
    virtual ~MovePIDOutput();
    void PIDWrite(double a);
    float speed;
};
