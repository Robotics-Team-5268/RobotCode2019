#include "CommandBase.h"
#include "subsystems/TrolleySPX.h"
//This class is deprecated
class Trolley : public CommandBase {
    private:
        TrolleySPX * trolleySPX;
        bool upT;
    public:
        Trolley(bool up);
        virtual void End();
        virtual void Initialize();
        virtual void Execute();
        virtual bool IsFinished();
        virtual void Interrupted();
        bool IsInterruptible() const;
};