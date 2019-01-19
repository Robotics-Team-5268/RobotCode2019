#pragma once

#include "SuspendableThread.h"
#include <atomic>   // For atomic variables.
#include <chrono>   // For millisecond duration type.
#include <cstdint>  // For standard type definitions.
#include <iomanip>  // For hex, setw, and setfill.
#include <thread>   // For thread and sleep_for.

class AutonomousChooser: public SuspendableThread {
public:
    AutonomousChooser();
    virtual ~AutonomousChooser();
    int AutonomousSelection();
private:
    int currentSelection;
protected:
    void OnRun();
};
