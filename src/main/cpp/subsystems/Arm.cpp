#include "subsystems/Arm.h"

Arm::Arm() : Subsystem("Arm") {

}

void Arm::MoveArm() {
  arm_SC.Set(0.4);
}

int Arm::GetCount() {
  return hallSensor.Get();
}