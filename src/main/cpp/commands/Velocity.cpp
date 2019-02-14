#include <frc/WPILib.h>
#include "CommandBase.h"
#include <frc/PIDController.h>
#include <frc/PIDOutput.h>
#include <frc/PIDSource.h>
#include "commands/Velocity.h"

Velocity::Velocity() : CommandBase("Velocity") {
    Requires(drive.get());
    leftPIDOutput = new VelocityPIDOutput(false);
    rightPIDOutput = new VelocityPIDOutput(true);
    leftPIDSource = new VelocityPIDSource(false);
    rightPIDSource = new VelocityPIDSource(true);
    setPointVelocity = 0;
}

bool Velocity::IsInterruptible() const{
    return true;
}

void Velocity::Interrupted() {
    End();
}

void Velocity::End() {
    leftPID->Disable();
    rightPID->Disable();
    delete leftPIDOutput;
    delete leftPIDSource;
    delete rightPIDOutput;
    delete rightPIDSource;
    delete leftPID;
    delete rightPID;
    drive->setMotors(0.0, 0.0);
}

void Velocity::Initialize() {
    leftPID = new frc::PIDController(
        frc::SmartDashboard::GetNumber("PLeftvelocity", .03),
        frc::SmartDashboard::GetNumber("ILeftvelocity", .005),
        frc::SmartDashboard::GetNumber("DLeftvelocity", .01),
        frc::SmartDashboard::GetNumber("FLeftvelocity", 0),
        leftPIDSource,
        leftPIDOutput
        );
    rightPID = new frc::PIDController(
        frc::SmartDashboard::GetNumber("PRightvelocity", .03),
        frc::SmartDashboard::GetNumber("IRightvelocity", .005),
        frc::SmartDashboard::GetNumber("DRightvelocity", .01),
        frc::SmartDashboard::GetNumber("FRightvelocity", 0),
        rightPIDSource,
        rightPIDOutput
        );
    leftPID->SetInputRange(-352.0, 352.0);
    leftPID->SetOutputRange(-1.0, 1.0);
    rightPID->SetInputRange(-352.0, 352.0);
    rightPID->SetOutputRange(-1.0, 1.0);
    leftPID->Enable();
    rightPID->Enable();  
}
    
void Velocity::Execute() {
    if(leftPID && rightPID){
        frc::SmartDashboard::PutNumber("PLeftPIDvelocity", leftPID->GetP());
        frc::SmartDashboard::PutNumber("ILeftPIDvelocity", leftPID->GetI());
        frc::SmartDashboard::PutNumber("DLeftPIDvelocity", leftPID->GetD());
        frc::SmartDashboard::PutNumber("FLeftPIDvelocity", leftPID->GetF());
        frc::SmartDashboard::PutNumber("PRightPIDvelocity", rightPID->GetP());
        frc::SmartDashboard::PutNumber("IRightPIDvelocity", rightPID->GetP());
        frc::SmartDashboard::PutNumber("DRightPIDvelocity", rightPID->GetP());
        frc::SmartDashboard::PutNumber("FRightPIDvelocity", rightPID->GetP());
    }
}
void Velocity::SetSetpoint(double inputVelocity){
    rightPID->SetSetpoint(inputVelocity);
    leftPID->SetSetpoint(inputVelocity);
}

//Returns false because velocity command must be killed by removing the command
bool Velocity::IsFinished() {
    return false;
}


VelocityPIDOutput::VelocityPIDOutput(bool right) {
    this->right = right;
    leftOutput = 0;
    rightOutput = 0;
}

VelocityPIDOutput::~VelocityPIDOutput() {
    
}

void VelocityPIDOutput::PIDWrite(double output) {
    if (right) {
        rightOutput = output;
    } else {
        leftOutput = output;
    }
    CommandBase::drive->setMotors(leftOutput, rightOutput);
}

VelocityPIDSource::VelocityPIDSource(bool right) {
    this->right = right;
}

VelocityPIDSource::~VelocityPIDSource() {
    
}

double VelocityPIDSource::PIDGet() {
    if (right) {
        return CommandBase::rightEncoder->getRate();
    } else {
        return CommandBase::leftEncoder->getRate();
    }
}