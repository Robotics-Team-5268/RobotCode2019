#include "commands/DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() : CommandBase("DriveWithJoystick") {
  Requires(drive.get());
}

void DriveWithJoystick::Initialize() {
}

void DriveWithJoystick::Execute() {
  drive->takeInput();
  frc::SmartDashboard::PutNumber("distance from target", CommandBase::sight->distanceFromTarget());
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
