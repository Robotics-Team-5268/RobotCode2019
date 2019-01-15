#include "Robot.h"
#include "subsystems/Drive.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>


void Robot::RobotInit() {
    CommandBase::init();
	CommandBase::drive->safetyOff();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() { 
    frc::Scheduler::GetInstance()->Run(); 
    AddSmartDashboardItems();
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() { 
    frc::Scheduler::GetInstance()->Run(); 
    AddSmartDashboardItems();
}

void Robot::TestPeriodic() {}

void Robot::AddSmartDashboardItems() {
    
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
