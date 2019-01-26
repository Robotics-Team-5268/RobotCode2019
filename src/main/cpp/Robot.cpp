#include "Robot.h"
#include "subsystems/Drive.h"
#include "CommandBase.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

std::unique_ptr<Autonomous> Robot::autonomousCommand;
AutonomousChooser Robot::AutoChooser;

void Robot::RobotInit() {
    CommandBase::init();
	CommandBase::drive->safetyOff();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::AutonomousInit() {
	autonomousCommand.reset(new Autonomous(AutoChooser.AutonomousSelection()));
	autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() { 
    frc::Scheduler::GetInstance()->Run();
    AddSmartDashboardItems();
}

void Robot::TeleopInit() {
	CommandBase::drive->resetGyro();
}

void Robot::TeleopPeriodic() { 
    frc::Scheduler::GetInstance()->Run(); 
    AddSmartDashboardItems();
}

void Robot::TestPeriodic() {}

void Robot::AddSmartDashboardItems() {
	frc::SmartDashboard::PutNumber("Gyro Angle", CommandBase::drive->getGyroAngle());
	frc::SmartDashboard::PutNumber("Gyro Rate", CommandBase::drive->getGyroRate());
	frc::SmartDashboard::PutNumber("rightcount", CommandBase::rightEncoder->getCount());
	frc::SmartDashboard::PutNumber("rightRaw Count", CommandBase::rightEncoder->getRaw());
	frc::SmartDashboard::PutNumber("rightDistance", CommandBase::rightEncoder->getDistance());
	frc::SmartDashboard::PutNumber("rightRate", CommandBase::rightEncoder->getRate());
	frc::SmartDashboard::PutBoolean("rightDirection", CommandBase::rightEncoder->getDirection());
	frc::SmartDashboard::PutBoolean("rightStopped", CommandBase::rightEncoder->getStopped());
	frc::SmartDashboard::PutNumber("leftcount", CommandBase::leftEncoder->getCount());
	frc::SmartDashboard::PutNumber("leftRaw Count", CommandBase::leftEncoder->getRaw());
	frc::SmartDashboard::PutNumber("leftDistance", CommandBase::leftEncoder->getDistance());
	frc::SmartDashboard::PutNumber("leftRate", CommandBase::leftEncoder->getRate());
	frc::SmartDashboard::PutBoolean("leftDirection", CommandBase::leftEncoder->getDirection());
	frc::SmartDashboard::PutBoolean("leftStopped", CommandBase::leftEncoder->getStopped());

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
