#include "commands/Autonomous.h"
#include "commands/Move.h"
#include "commands/VelocityTest.h"

Autonomous::Autonomous(int selection) : CommandBase("Autonomous") {
  std::string gameData;
  gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
  AddSequential(new VelocityTest());
}