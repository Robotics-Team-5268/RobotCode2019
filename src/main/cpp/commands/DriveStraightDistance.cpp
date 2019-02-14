#include <frc/WPILib.h>
#include "commands/DriveStraightDistance.h"
#include "subsystems/Encoders.h"
#include "commands/Velocity.h"



void DriveStraightDistance::End(){
    velocity->done = true;
    //velocity->End();
}

void DriveStraightDistance::Initialize(){
    velocity = new Velocity();
    //velocity->Initialize();
    velocity->Start();
    //AddSequential(velocity);
    startingLeft = CommandBase::leftEncoder->getDistance();
    startingRight = CommandBase::rightEncoder->getDistance();
}

void DriveStraightDistance::Execute(){
    /*if (velocity == nullptr){
        return;
    }*/
    double currentDistance = (CommandBase::leftEncoder->getDistance() + (CommandBase::rightEncoder->getDistance() * 7)) / 2;
    double velocityPIDInput = 0;
    if (currentDistance < ACCELERATION_DISTANCE) {
        //This is when we start accelerating
        velocityPIDInput = ACCELERATION * currentDistance;
        if(velocityPIDInput < .1){ velocityPIDInput = .1;}
    } else if (currentDistance >= ACCELERATION_DISTANCE && currentDistance < distance - DECELERATION_DISTANCE) {
        //This is when we stay at a constant velocity
        velocityPIDInput = MAX_VELOCITY;
    } else {
        //This is when we to start to deaccelerate
        velocityPIDInput = -MAX_VELOCITY * ((currentDistance - distance)/DECELERATION_DISTANCE);
    }
    frc::SmartDashboard::PutNumber("Setpoint", velocityPIDInput);

    velocity->SetSetpoint(velocityPIDInput);
    //velocity->Execute();
}

bool DriveStraightDistance::IsFinished(){
    if ((CommandBase::leftEncoder->getDistance() + (CommandBase::rightEncoder->getDistance() * 7)) / 2 > distance) {
        return true;
    }
    return false;
}

DriveStraightDistance::DriveStraightDistance(double distance) : CommandBase("DriveStraightDistance") {
    this->distance = distance;
    frc::SmartDashboard::PutNumber("distance", distance);
}