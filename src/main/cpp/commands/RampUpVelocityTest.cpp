#include "commands/RampUpVelocityTest.h"

RampUpVelocityTest::RampUpVelocityTest() 
: fout("/home/lvuser/TestValue.csv"),
pdp()
{
  driveCommand = 0.0;
  count = 0;
  fout << "Percent Power,Left Velocity,Right Velocity" << '\n';
}

void RampUpVelocityTest::Initialize() {}

void RampUpVelocityTest::Execute() {
    if (count == 5) {
      driveCommand += 0.02;
      count = 0;
    } else {
      count++;
    }
    drive->FindVelocity(driveCommand, driveCommand);
    double left = CommandBase::leftEncoder->getRate();
    double right = CommandBase::rightEncoder->getRate();
    fout << driveCommand << "," << left << "," << right << '\n';
}

bool RampUpVelocityTest::IsFinished() {
    return (5 <= count && driveCommand == 1);
}

void RampUpVelocityTest::End() {
    fout.close();
}

void RampUpVelocityTest::Interrupted() {}