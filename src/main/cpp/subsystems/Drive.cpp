#include "subsystems/Drive.h"
#include "commands/DriveWithJoystick.h"
#include <frc/smartDashBoard/SmartDashBoard.h>

Drive::Drive() : Subsystem("Drive") {
	oldLeftSpeed = 0.0;
	oldRightSpeed = 0.0;
	velocityToCommandIntercept[0] = -316.89;
	velocityToCommandIntercept[1] = -378.00;
	velocityToCommandIntercept[2] = -364.78;
	velocityToCommandIntercept[3] = -331.27;
	velocityToCommandSlope[0] = 1/3493.57;
	velocityToCommandSlope[1] = 1/3493.90;
	velocityToCommandSlope[2] = 1/3386.53;
	velocityToCommandSlope[3] = 1/3744,83;
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

void Drive::setVelocity(float left, float right) {
	if (left < 0) {
		left = velocityToCommandSlope[0]*left + velocityToCommandIntercept[0];
	} else {
		left = velocityToCommandSlope[2]*left + velocityToCommandIntercept[2];
	}
	if (right < 0) {
		right = velocityToCommandSlope[1]*right + velocityToCommandIntercept[1];
	} else {
		right = velocityToCommandSlope[3]*right + velocityToCommandIntercept[3];
	}
	setMotors(left, right);
}
//what is this method supposed to do? it doesn't find our current velocity so i dont know what it is for.
void Drive::findVelocity(float left, float right) {
	//float left = -CommandBase::oi->getDriverJoystick()->GetRawAxis(1);
	//float right = -CommandBase::oi->getDriverJoystick()->GetRawAxis(5);
	left = left*3000;
	right = right*3000;
	setVelocity(left, right);
}