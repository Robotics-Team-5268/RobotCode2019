#include "CommandBase.h"
#include "subsystems/Encoders.h"
#include "subsystems/Drive.h"
#include "subsystems/UDPReceiver.h"
#include "subsystems/Sighting.h"

std::unique_ptr<Drive> CommandBase::drive;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<UDPReceiver> CommandBase::udp;
std::unique_ptr<Sighting> CommandBase::sight;

CommandBase::CommandBase(const std::string &name) : frc::CommandGroup(name) {
  
}

CommandBase::CommandBase() : frc::CommandGroup() {

}

void CommandBase::init() {
    drive.reset(new Drive());
    udp.reset(new UDPReceiver());
    sight.reset(new Sighting());
    // Keep at the end
	oi.reset(new OI());
}