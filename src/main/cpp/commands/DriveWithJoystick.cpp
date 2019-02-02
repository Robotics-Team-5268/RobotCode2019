#include "commands/DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() : CommandBase("DriveWithJoystick") {
  Requires(drive.get());
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
  drive->FindVelocity(
    -CommandBase::oi->getDriverJoystick()->GetRawAxis(1) ,
	  -CommandBase::oi->getDriverJoystick()->GetRawAxis(5)
    // 0.0,0.0
  );
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
