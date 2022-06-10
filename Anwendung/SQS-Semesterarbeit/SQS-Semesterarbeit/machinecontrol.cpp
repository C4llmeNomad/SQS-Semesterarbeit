#include "machinecontrol.h"

MachineControl::MachineControl()
{
    m_hasConnection = false;
    m_isRunning = false;
    m_hasErrors = false;
    m_eStopActivated = false;
}

void MachineControl::error()
{
    if (m_hasConnection){
        emit machineRunning(false);
        m_isRunning = false;

        emit resetAllErrors(false);
        m_hasErrors = true;
    }
}

void MachineControl::startMachine()
{
    if (m_hasConnection && !m_isRunning && !m_hasErrors && !m_eStopActivated){
        emit machineRunning(true);
        m_isRunning = true;
    }
}

void MachineControl::emergencyStop()
{
    if (m_hasConnection){
        emit eStopActivated(true);
        m_eStopActivated = true;

        emit machineRunning(false);
        m_isRunning = false;
    }
}

void MachineControl::resetErrorAndEStop()
{
    if (m_hasConnection && (m_hasErrors || m_eStopActivated)){
        emit resetAllErrors(true);
        m_hasErrors = false;

        emit resetEStop(false);
        m_eStopActivated = false;
    }
}

void MachineControl::connect()
{
    emit connected(true);
    m_hasConnection = true;
}

void MachineControl::disconnect()
{
    if (m_hasConnection){
        emit connected(false);
        m_hasConnection = false;
    }
}


