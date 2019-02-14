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
	velocityToCommandSlope[3] = 1/3744.83;
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

	if (leftSpeed > oldLeftSpeed + MAX_CHANGE) leftSpeed = oldLeftSpeed + MAX_CHANGE;
	else if (leftSpeed < oldLeftSpeed - MAX_CHANGE) leftSpeed = oldLeftSpeed - MAX_CHANGE;
	if (rightSpeed > oldRightSpeed + MAX_CHANGE) rightSpeed = oldRightSpeed + MAX_CHANGE;
	else if (rightSpeed < oldRightSpeed - MAX_CHANGE) rightSpeed = oldRightSpeed - MAX_CHANGE;

    if (leftSpeed >= .9 && rightSpeed >= .9) {
	  setMotors(1, 1);
    } else {
	  setMotors(leftSpeed, rightSpeed);
    }

    oldLeftSpeed = leftSpeed;
	oldRightSpeed = rightSpeed;


	//fout << getGyroRate() << '\n';
}

void Drive::setMotors(float leftSpeed, float rightSpeed) {
	diffDrive.TankDrive(leftSpeed, rightSpeed, false);

	frc::SmartDashboard::PutNumber("Speed Controller FL", speedControllerFL.Get());
	frc::SmartDashboard::PutNumber("Speed Controller FR", speedControllerFR.Get());
	frc::SmartDashboard::PutNumber("Speed Controller BL", speedControllerBL.Get());
	frc::SmartDashboard::PutNumber("Speed Controller BR", speedControllerBR.Get());
}

frc::AnalogGyro* Drive::getGyro() {
	return &gyro;
}
float Drive::getGyroAngle() {
	return gyro.GetAngle();
}
float Drive::getGyroRate() {
	return gyro.GetRate();
}
void Drive::resetGyro() {
	gyro.Reset();
}
void Drive::calibrateGyro() {
	gyro.Calibrate();
}

void Drive::SetVelocity(float left, float right) {
	float leftSpeed = left * MAX_SPEED;
	float rightSpeed = right * MAX_SPEED;
	if (leftSpeed < 0) {
		leftSpeed = velocityToCommandSlope[0]*(leftSpeed + velocityToCommandIntercept[0]);
	} else {
		leftSpeed = velocityToCommandSlope[2]*(leftSpeed + velocityToCommandIntercept[2]);
	}
	if (rightSpeed < 0) {
		rightSpeed = velocityToCommandSlope[1]*(rightSpeed + velocityToCommandIntercept[1]);
	} else {
		rightSpeed = velocityToCommandSlope[3]*(rightSpeed + velocityToCommandIntercept[3]);
	}
	setMotors(left, rightSpeed);
}