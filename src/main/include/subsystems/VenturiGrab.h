#pragma once
#include <frc/commands/Subsystem.h>
#include "frc/WPILib.h"

class VenturiGrab : public frc::Subsystem {
 private:
  frc::Servo *venturiServo;
  frc::Solenoid venturiSolenoid {10, 0};
  //true = on; false = closed.
  bool solenoidPosition;
 public:
  VenturiGrab();
  void SetDegrees(int degrees);
  void SetSolenoid(bool state);
  void ToggleSolenoid();
  void InitDefaultCommand() override;
};
