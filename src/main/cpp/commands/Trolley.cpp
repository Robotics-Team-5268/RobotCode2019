#include "CommandBase.h"
#include "subsystems/TrolleySPX.h"
#include "commands/Trolley.h"
#include "RobotMap.h"

Trolley::Trolley(bool up) {
    trolleySPX = new TrolleySPX(TROLLEY_VICTOR_SPX_CAN_BUS_ID);
    upT = up;
}

void Trolley::End() {
    trolleySPX->setTrolleyOff();
    delete trolleySPX;
}
        
void Trolley::Initialize() {
    trolleySPX->setTrolleyOn(upT);
}

void Trolley::Execute() {}

bool Trolley::IsFinished() {
    return false;
}

void Trolley::Interrupted() {
    End();
}

bool IsInterruptible() {
    return true;
}