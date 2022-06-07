#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "machinecontrol.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

public slots:
    void updateConnectionDisplay(bool connected);
    void updateErrorDisplay(bool errors);
    void updateEStopDisplay(bool eStop);
    void updateRunningDisplay(bool running);

private:
    void initStatusDisplay();
    void initSpeedSlider();
    void updateSliderValue();
    void initMachineControl();

private:
    Ui::MainWindow *ui;

    MachineControl *m_machineControl;
    const QString colorGreen = "rgb(27, 193, 00)";
    const QString colorRed = "rgb(203, 47, 47)";
    const QString colorYellow = "rgb(255, 254, 145)";
    const QString colorGrey = "rgb(218, 218, 218)";
};
#endif // MAINWINDOW_H
