#include "subsystems/Grabber.h"

Grabber::Grabber() : Subsystem("Grabber") {
    //I have no idea if the inverts are correct here, if the intake/output go backwards then flip the trues to falses
    speedControllerL.SetInverted(false);
    speedControllerR.SetInverted(true);
}

void Grabber::SetMotors(double speed){
    //GrabberSCG.Set(speed);
    //if the above line does not work, uncomment this block to ungroup the speed controllers
    speedControllerL.Set(speed);
    speedControllerR.Set(speed);
    
}