#pragma once

#include <memory>

#include <frc/commands/CommandGroup.h>
#include <string.h>

#include "subsystems/Drive.h"
#include "OI.h"

class CommandBase : public frc::CommandGroup {
 public:
  CommandBase(const std::string &name);
  CommandBase();
  static void init();

  static std::unique_ptr<Drive> drive;
  static std::unique_ptr<OI> oi;
};
