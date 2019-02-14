#ifndef DRIVE_STRAIGHT_DISTANCE_H
#define DRIVE_STRAIGHT_DISTANCE_H
#define MAX_VELOCITY .6
#define ACCELERATION_DISTANCE 3
#define ACCELERATION (MAX_VELOCITY / ACCELERATION_DISTANCE)
#include "CommandBase.h"
#include "commands/Velocity.h"

class DriveStraightDistance : public CommandBase {
private:   
    double distance;
    Velocity* velocity = nullptr;
public:
    virtual void End();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    DriveStraightDistance(double distance);
};

#endif