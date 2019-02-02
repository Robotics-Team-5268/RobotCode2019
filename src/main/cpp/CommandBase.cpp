#include "CommandBase.h"
#include "subsystems/Encoders.h"
#include "subsystems/Drive.h"
#include "subsystems/UDPReceiver.h"
#include "subsystems/Sighting.h"

std::unique_ptr<Drive> CommandBase::drive;
std::unique_ptr<Encoders> CommandBase::leftEncoder;
std::unique_ptr<Encoders> CommandBase::rightEncoder;
std::unique_ptr<Encoders> CommandBase::elevatorEncoder;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<UDPReceiver> CommandBase::udp;
std::unique_ptr<Sighting> CommandBase::sight;
std::unique_ptr<MB1013Ultrasonic> CommandBase::ultrasonic;

CommandBase::CommandBase(const std::string &name) : frc::CommandGroup(name) {
  
}

CommandBase::CommandBase() : frc::CommandGroup() {

}

void CommandBase::init() {
    drive.reset(new Drive());
    udp.reset(new UDPReceiver());
    sight.reset(new Sighting());
    leftEncoder.reset(new Encoders("left", 4, 5, false));
	rightEncoder.reset(new Encoders("right", 3, 2, false));
    elevatorEncoder.reset(new Encoders("right", 0, 1, false));
    ultrasonic.reset(new MB1013Ultrasonic());
    // Keep at the end
	oi.reset(new OI());
}