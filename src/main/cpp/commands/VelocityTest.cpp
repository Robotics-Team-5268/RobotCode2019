#include "commands/VelocityTest.h"

VelocityTest::VelocityTest() {
  driveCommand = 0.0;
  count = 0;
}

void VelocityTest::Initialize() {}

void VelocityTest::Execute() {
    if (count == 5) {
        driveCommand += 0.05;
        count = 0;
    } else {
        count++;
    }
}

bool VelocityTest::IsFinished() { 
    return (1.0 <= driveCommand && 5 <= count); 
}

void VelocityTest::End() {}

void VelocityTest::Interrupted() {}
