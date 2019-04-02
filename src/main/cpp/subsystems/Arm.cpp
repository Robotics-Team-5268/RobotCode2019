#include "subsystems/Arm.h"

Arm::Arm() : Subsystem("Arm") {

}

void Arm::InitDefaultCommand(){

}

void Arm::MoveArm(double speed) {
  arm_SC.Set(speed);
}

/*int Arm::GetCount() {
  return hallSensor.Get();
}*/