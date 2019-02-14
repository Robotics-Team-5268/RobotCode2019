#include <frc/WPILib.h>
#include "commands/DriveStraightDistance.h"
#include "subsystems/Encoders.h"
#include "commands/Velocity.h"



void DriveStraightDistance::End(){

}

void DriveStraightDistance::Initialize(){
    velocity = new Velocity();
}

void DriveStraightDistance::Execute(){
    if (velocity == nullptr){
        return;
    }
    
    double velocityPIDInput;
    if ((CommandBase::leftEncoder->getDistance() + CommandBase::rightEncoder->getDistance()) / 2 < ACCELERATION_DISTANCE) {
        //This is when we start accelerating
        velocityPIDInput = ACCELERATION * (CommandBase::leftEncoder->getDistance() + CommandBase::rightEncoder->getDistance()) / 2;
        
    } else if ((CommandBase::leftEncoder->getDistance() + CommandBase::rightEncoder->getDistance()) / 2 >= ACCELERATION_DISTANCE && (CommandBase::leftEncoder->getDistance() + CommandBase::rightEncoder->getDistance()) / 2 < distance - ACCELERATION_DISTANCE) {
        //This is when we stay at a constant velocity
        velocityPIDInput = MAX_VELOCITY;
    } else {
        //This is when we to start to deaccelerate
        velocityPIDInput = -MAX_VELOCITY * (((CommandBase::leftEncoder->getDistance() + CommandBase::rightEncoder->getDistance()) / 2) - distance);
    }

    velocity->SetSetpoint(velocityPIDInput);
}

bool DriveStraightDistance::IsFinished(){
    if ((CommandBase::leftEncoder->getDistance() + CommandBase::rightEncoder->getDistance()) / 2 > distance) {
        return true;
    }
    return false;
}

DriveStraightDistance::DriveStraightDistance(double distance) : CommandBase("DriveStraightDistance") {
    
    this->distance = distance;
}