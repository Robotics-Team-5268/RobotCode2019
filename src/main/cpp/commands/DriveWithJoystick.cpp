#include "commands/DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() : CommandBase("DriveWithJoystick") {
  Requires(drive.get());
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
  drive->takeInput();
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
