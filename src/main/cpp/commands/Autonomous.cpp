#include "commands/Autonomous.h"
#include "commands/Move.h"

Autonomous::Autonomous(int selection) {
  std::string gameData;
  gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
  
}