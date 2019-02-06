#include "subsystems/Grabber.h"

Grabber::Grabber() : Subsystem("Grabber") {
    //I have no idea if the inverts are correct here, if the intake/output go backwards then flip the trues to falses
    speedControllerL.SetInverted(false);
    speedControllerR.SetInverted(true);
}

void Grabber::GrabberIntake() {
    GrabberSCG.Set(0.6);
}
void Grabber::GrabberOff() {
    GrabberSCG.Set(0.0);
}
void Grabber::GrabberOutput() {
    GrabberSCG.Set(-0.4);
}