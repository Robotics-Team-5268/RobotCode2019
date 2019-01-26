#include "commands/VelocityTest.h"

VelocityTest::VelocityTest() 
: fout("/home/lvuser/TestValue.csv"),
pdp()
{
  driveCommand = 0.6;
  count = 0;
  fout << "Front Left,Front Right,Back Left,Back Right,LeftEncoderVelocity,RightEncoderVelocity" << '\n';
}

void VelocityTest::Initialize() {}

void VelocityTest::Execute() {
    count++;
    drive->FindVelocity(driveCommand, driveCommand);
    double left = CommandBase::leftEncoder->getRate();
    double right = CommandBase::rightEncoder->getRate();
    fout << pdp.GetCurrent(1) << "," << pdp.GetCurrent(2) << "," << pdp.GetCurrent(0) << "," << pdp.GetCurrent(3) << "," << left << "," << right << '\n';
}

bool VelocityTest::IsFinished() {
    return (200 <= count);
}

void VelocityTest::End() {
    fout.close();
}

void VelocityTest::Interrupted() {}

