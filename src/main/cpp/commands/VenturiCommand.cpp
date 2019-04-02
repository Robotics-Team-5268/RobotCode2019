#include "commands/VenturiCommand.h"
#include "subsystems/VenturiGrab.h"
#include <chrono>
#include <thread>
#include "RobotMap.h"
//1=open; 2=close; 3=release
VenturiCommand::VenturiCommand(int action) {
  //Requires(CommandBase::vent.get());
  Action = action;
}

void VenturiCommand::Initialize() {}

void VenturiCommand::Execute() {
  //CommandBase::vent->SetDegrees(Degrees);
  //CommandBase::vent->ToggleSolenoid();
  //opens the solenoid to get suction
  
  if (Action == 1){
    CommandBase::vent->SetSolenoid(true);
  }
  //closes the servo motor to maintain suction, then turns off solenoid
  if (Action == 2){
    CommandBase::vent->SetDegrees(CLOSED_DEGREES);
    //wait until the servo motor is closed
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    CommandBase::vent->SetSolenoid(false);
  }
  //opens the servo motor to release the hatch
  if (Action == 3){
    CommandBase::vent->SetDegrees(OPEN_DEGREES);
  }
  
}

bool VenturiCommand::IsFinished() { return true; }

void VenturiCommand::End() {}

void VenturiCommand::Interrupted() {}
