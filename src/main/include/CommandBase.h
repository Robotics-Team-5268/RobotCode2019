#pragma once

#include <memory>

#include <frc/commands/CommandGroup.h>
#include <string.h>

#include "subsystems/UDPReceiver.h"
#include "subsystems/Drive.h"
#include "subsystems/Sighting.h"
#include "subsystems/Encoders.h"
#include "subsystems/MB1013Ultrasonic.h"
#include "OI.h"

class CommandBase : public frc::CommandGroup {
 public:
  CommandBase(const std::string &name);
  CommandBase();
  static void init();

  
  static std::unique_ptr<Drive> drive;
  static std::unique_ptr<Encoders> leftEncoder;
  static std::unique_ptr<Encoders> rightEncoder;
    static std::unique_ptr<Encoders> elevatorEncoder;
  static std::unique_ptr<MB1013Ultrasonic> ultrasonic;
  static std::unique_ptr<OI> oi;
  static std::unique_ptr<UDPReceiver> udp;
  static std::unique_ptr<Sighting> sight;
};
