#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/drive/DifferentialDrive.h>

#include "RobotMap.h"

//I want to make take and place item commands into one class so you will see a new command called GrabberCommand
//I left the two commands you made but if you want to get rid of them go ahead
//I feel that lower level things like what direction the wheels spin should be handled at the subsystem level
//which is why I made two methods in this class, one to handle input and another for output
//the third method is just called at the end of the GrabberCommand and sets the motors to 0 so they don't run indefinitly
class Grabber : public frc::Subsystem {
 private:
  frc::Talon speedControllerL{GRABBER_SPEED_CONTROLLER_L_CHANNEL};
	frc::Talon speedControllerR{GRABBER_SPEED_CONTROLLER_R_CHANNEL};
  frc::SpeedControllerGroup GrabberSCG{speedControllerL, speedControllerR};
 public:
  Grabber();
  void GrabberIntake();
  void GrabberOutput();
  void GrabberOff();
};
