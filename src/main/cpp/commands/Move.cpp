#include "commands/Move.h"

Move::Move(float tm, float spd) : CommandBase() {
  Requires(drive.get());
  pid = nullptr;
  seconds = tm;
  speed = spd;
  timer.reset(new frc::Timer());
}

void Move::Initialize() {}

void Move::Execute() {
  if(pid) {
    
  }
}

bool Move::IsFinished() { 
  return timer->HasPeriodPassed(seconds); 
  }

void Move::End() {}

void Move::Interrupted() {}
