#ifndef MACHINESCONTROL_H
#define MACHINESCONTROL_H

#include <QObject>



class MachineControl : public QObject
{
    Q_OBJECT
public:
    MachineControl();

public slots:
    void startMachine();
    void emergencyStop();
    void errorReset();
    void connect();

signals:
    void connected(bool connected);
    void resetAllErrors(bool resetAllErrors);
    void machineRunning(bool running);
    void eStopActivated(bool eStop);

private:
    bool m_connection;
    bool m_error;
    bool m_eStop;
    bool m_running;
};

#endif // MACHINESCONTROL_H
