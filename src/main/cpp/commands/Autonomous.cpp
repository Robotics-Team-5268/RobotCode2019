#include "commands/Autonomous.h"
#include "commands/Move.h"
#include "commands/VelocityTest.h"
#include "commands/RampUpVelocityTest.h"
#include "commands/DriveStraightDistance.h"
#include "commands/VenturiCommand.h"
Autonomous::Autonomous(int selection) : CommandBase("Autonomous") {
  //std::string gameData;
  //gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
  //AddSequential(new VelocityTest());
  //AddSequential(new RampUpVelocityTest());
  //AddSequential(new VenturiCommand(1));
  //AddSequential(new VenturiCommand(2));
  //AddSequential(new DriveStraightDistance(48));

}