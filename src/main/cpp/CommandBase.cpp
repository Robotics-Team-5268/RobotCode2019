#include "CommandBase.h"
#include "subsystems/Encoders.h"
#include "subsystems/Drive.h"
#include "subsystems/UDPReceiver.h"
#include "subsystems/Sighting.h"
#include "subsystems/Elevator.h"

#include <Subsystems/Encoders.h>

std::unique_ptr<Drive> CommandBase::drive;
std::unique_ptr<Encoders> CommandBase::leftEncoder;
std::unique_ptr<Encoders> CommandBase::rightEncoder;
std::unique_ptr<Encoders> CommandBase::elevatorEncoder;
std::unique_ptr<Elevator> CommandBase::elevator;
std::unique_ptr<Grabber> CommandBase::grabber;
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<Arm> CommandBase::arm;
std::unique_ptr<Pneumatics> CommandBase::pneumatics;
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
    leftEncoder.reset(new Encoders("left", 3, 2, false));
	rightEncoder.reset(new Encoders("right", 1, 0, false));
    elevatorEncoder.reset(new Encoders("elevator", 4, 5, false));
    grabber.reset(new Grabber());
    arm.reset(new Arm());
    pneumatics.reset(new Pneumatics());
    ultrasonic.reset(new MB1013Ultrasonic());
    elevator.reset(new Elevator());
    // Keep at the end
	oi.reset(new OI());
}