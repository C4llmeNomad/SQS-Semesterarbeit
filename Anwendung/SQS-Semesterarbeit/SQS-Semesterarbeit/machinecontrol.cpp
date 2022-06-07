#include "machinecontrol.h"

MachineControl::MachineControl()
{

}

void MachineControl::startMachine()
{
    emit machineRunning(true);
}

void MachineControl::emergencyStop()
{
    emit eStopActivated(true);

    emit machineRunning(false);
}

void MachineControl::errorReset()
{
    emit resetAllErrors(true);
}

void MachineControl::connect()
{
    emit connected(true);
}


