#ifndef DRIVE_STRAIGHT_DISTANCE_H
#define DRIVE_STRAIGHT_DISTANCE_H
#define MAX_VELOCITY .3
#define ACCELERATION_DISTANCE 20
#define DECELERATION_DISTANCE 47
#define ACCELERATION (MAX_VELOCITY / ACCELERATION_DISTANCE)
#define DECELERATION (MAX_VELOCITY / DECELERATION_DISTANCE)
#include "CommandBase.h"
#include "commands/Velocity.h"

class DriveStraightDistance : public CommandBase {
private:   
    double distance, startingRight, startingLeft;
    Velocity* velocity;
public:
    virtual void End();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    DriveStraightDistance(double distance);
};

#endif