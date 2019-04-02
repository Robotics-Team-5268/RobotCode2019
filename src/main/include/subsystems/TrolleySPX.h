#ifndef TROLLEY_H
#define TROLLEY_H
#define DEFAULT_SPEED 0.2
#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
//This class is deprecated
//not needed. the trolly and elevator are controlled by the same motor that will have a talon srx so the elevator class will be used instead of this
class TrolleySPX : public frc::Subsystem {
    private:
        ctre::phoenix::motorcontrol::can::WPI_VictorSPX * trolleyMotorController;
    public:
        TrolleySPX(int canBusID);
        ~TrolleySPX();
        void setTrolleyOn(bool up);
        void setTrolleyOff();
};

#endif