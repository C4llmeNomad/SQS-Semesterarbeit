#ifndef MACHINESCONTROL_H
#define MACHINESCONTROL_H

#include <QObject>



class MachineControl : public QObject
{
    Q_OBJECT
public:
    MachineControl();
    void error();
    void disconnect();

public slots:
    void startMachine();
    void emergencyStop();
    void resetErrorAndEStop();
    void connect();

signals:
    void connected(bool connected);
    void resetAllErrors(bool resetAllErrors);
    void machineRunning(bool running);
    void eStopActivated(bool eStop);
    void resetEStop(bool eStop);

private:
    bool m_hasConnection;
    bool m_hasErrors;
    bool m_eStopActivated;
    bool m_isRunning;
};

#endif // MACHINESCONTROL_H
