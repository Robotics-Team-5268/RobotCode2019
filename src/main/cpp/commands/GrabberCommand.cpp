#include "commands/GrabberCommand.h"
#include "CommandBase.h"
//This does not work but I am not sure whether the problem lies within Grabber or Grabber command
//This looks like the error is within the subsystem
GrabberCommand::GrabberCommand(double spd) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::grabber.get());
  speed = spd;
}

// Called just before this Command runs the first time
void GrabberCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void GrabberCommand::Execute() {
  CommandBase::grabber->SetMotors(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool GrabberCommand::IsFinished() { return true; }

// Called once after isFinished returns true
void GrabberCommand::End() {
  
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabberCommand::Interrupted() {}
