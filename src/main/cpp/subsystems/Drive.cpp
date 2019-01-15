#include "subsystems/Drive.h"
#include "commands/DriveWithJoystick.h"
#include <frc/smartDashBoard/SmartDashBoard.h>

Drive::Drive() : Subsystem("Drive") {
	oldLeftSpeed = 0.0;
	oldRightSpeed = 0.0;
	speedControllerFL.SetInverted(SCFL_INVERTED);
	speedControllerBL.SetInverted(SCBL_INVERTED);
	speedControllerFR.SetInverted(SCFR_INVERTED);
	speedControllerBR.SetInverted(SCBR_INVERTED);

}

void Drive::InitDefaultCommand() {
  SetDefaultCommand(new DriveWithJoystick());
}

void Drive::takeInput() {
	float leftSpeed = -CommandBase::oi->getDriverJoystick()->GetRawAxis(1);
	float rightSpeed = -CommandBase::oi->getDriverJoystick()->GetRawAxis(5);
  if (leftSpeed >= .9 && rightSpeed >= .9) {
	  setMotors(1, 1);
  } else {
	  setMotors(leftSpeed, rightSpeed);
  }
}

void Drive::setMotors(float leftSpeed, float rightSpeed) {
	if (leftSpeed > oldLeftSpeed + MAX_CHANGE) leftSpeed = oldLeftSpeed + MAX_CHANGE;
	else if (leftSpeed < oldLeftSpeed - MAX_CHANGE) leftSpeed = oldLeftSpeed - MAX_CHANGE;
	if (rightSpeed > oldRightSpeed + MAX_CHANGE) rightSpeed = oldRightSpeed + MAX_CHANGE;
	else if (rightSpeed < oldRightSpeed - MAX_CHANGE) rightSpeed = oldRightSpeed - MAX_CHANGE;

	diffDrive.TankDrive(leftSpeed, rightSpeed, false);

	frc::SmartDashboard::PutNumber("Speed Controller FL", speedControllerFL.Get());
	frc::SmartDashboard::PutNumber("Speed Controller FR", speedControllerFR.Get());
	frc::SmartDashboard::PutNumber("Speed Controller BL", speedControllerBL.Get());
	frc::SmartDashboard::PutNumber("Speed Controller BR", speedControllerBR.Get());

	oldLeftSpeed = leftSpeed;
	oldRightSpeed = rightSpeed;
}