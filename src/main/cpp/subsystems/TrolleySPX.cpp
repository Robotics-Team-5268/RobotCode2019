#include "subsystems/TrolleySPX.h"
#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"

TrolleySPX::TrolleySPX(int canBusID) : Subsystem("Trolley") {
    trolleyMotorController = new WPI_VictorSPX(canBusID);
}

void TrolleySPX::setTrolleyOn(bool up) {
    //If up is true, then set motors to a constant positive speed. Otherwise the speed is negative
    if (up) {
        trolleyMotorController->Set(DEFAULT_SPEED);
    } else {
        trolleyMotorController->Set(-DEFAULT_SPEED);
    }
    return;
}

//This is so we can set our motors to be off
void TrolleySPX::setTrolleyOff() {
    trolleyMotorController->Set(0.0);
}

TrolleySPX::~TrolleySPX() {
    delete trolleyMotorController;
}