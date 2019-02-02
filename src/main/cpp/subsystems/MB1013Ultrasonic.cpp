#include "subsystems/MB1013Ultrasonic.h"

MB1013Ultrasonic::MB1013Ultrasonic() : Subsystem("MB1013Ultrasonic") {}

double MB1013Ultrasonic::getVoltage() {
  return ultrasonic.GetVoltage();
}