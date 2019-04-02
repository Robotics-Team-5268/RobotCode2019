#include "subsystems/VenturiGrab.h"

VenturiGrab::VenturiGrab() : Subsystem("ExampleSubsystem") {
  venturiServo = new frc::Servo(0);
}

void VenturiGrab::InitDefaultCommand() {
  
}

void VenturiGrab::SetDegrees(int degrees){
  venturiServo->SetAngle(degrees);
}

void VenturiGrab::SetSolenoid(bool state){
  venturiSolenoid.Set(state);
  solenoidPosition = state;
}

void VenturiGrab::ToggleSolenoid(){
  if(solenoidPosition){
    venturiSolenoid.Set(false);
    solenoidPosition = false;
  }
  else{
    venturiSolenoid.Set(true);
    solenoidPosition = true;
  }
}
