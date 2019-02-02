#include "commands/Autonomous.h"
#include "commands/Move.h"
#include "commands/VelocityTest.h"
#include "commands/RampUpVelocityTest.h"

Autonomous::Autonomous(int selection) : CommandBase("Autonomous") {
  std::string gameData;
  gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
  //AddSequential(new VelocityTest());
  AddSequential(new RampUpVelocityTest());
}