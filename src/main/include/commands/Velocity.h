#ifndef VELOCITY_H
#define VELOCITY_H

#include "CommandBase.h"
#include <frc/PIDController.h>
#include <frc/PIDOutput.h>
#include <frc/PIDSource.h>
//NOTICE: PLEASE READ: If encoders are not already required by the command you are calling this from,
//then you must add it to that command.

class VelocityPIDOutput: public frc::PIDOutput {
    private:
        double leftOutput , rightOutput ;
        bool right;
    public:
    VelocityPIDOutput(bool right);
    virtual ~VelocityPIDOutput();
    virtual void PIDWrite(double output);
};

class VelocityPIDSource: public frc::PIDSource {
    private:
        bool right;
    public:
    VelocityPIDSource(bool right);
    virtual ~VelocityPIDSource();
    virtual double PIDGet();
};

class Velocity : public CommandBase {
    private:
    double setPointVelocity;
        frc::PIDController * leftPID, * rightPID;
        frc::PIDSource * rightPIDSource, * leftPIDSource;
        frc::PIDOutput * rightPIDOutput, * leftPIDOutput;
    public:
        Velocity();
        virtual void End();
        virtual void Initialize();
        virtual void Execute();
        virtual bool IsFinished();
        virtual void Interrupted();
        void SetSetpoint(double inputVelocity);
        bool IsInterruptible() const;
       
};
#endif