#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QString>




/* Connect Button der ne Weile sinnlose dinge tut, dann label umstellt und Text zu reconnect macht x
 * slider für geschwindigkeit Y
 * Button für Start und Stop Y
 * Text Input, Checkbox für ??? -> Settingsdialog
 * Label (Status) Anzeige Y
 */


MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initStatusDisplay();
    initMachineControl();
    initSpeedSlider();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initStatusDisplay()
{
    m_machineControl = new MachineControl();

    ui->label_connectionStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorRed));
    connect(m_machineControl, &MachineControl::connected, this, &MainWindow::updateConnectionDisplay);


    ui->label_errorStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorGreen));
    connect(m_machineControl, &MachineControl::resetAllErrors, this, &MainWindow::updateErrorDisplay);

    ui->label_eStopStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorGreen));
    connect(m_machineControl, &MachineControl::eStopActivated, this, &MainWindow::updateEStopDisplay);

    ui->label_runningStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorGrey));
    connect(m_machineControl, &MachineControl::machineRunning, this, &MainWindow::updateRunningDisplay);
}

void MainWindow::initMachineControl()
{
    connect(ui->pushButton_start, &QPushButton::pressed, m_machineControl, &MachineControl::startMachine);

    connect(ui->pushButton_stop, &QPushButton::pressed, m_machineControl, &MachineControl::emergencyStop);

    connect(ui->pushButton_connect, &QPushButton::pressed, m_machineControl, &MachineControl::connect);

    connect(ui->pushButton_errorReset, &QPushButton::pressed, m_machineControl, &MachineControl::errorReset);
}

void MainWindow::initSpeedSlider()
{
    ui->label_speedValue->setText(QString::number(ui->horizontalSlider_speed->value()));
    connect(ui->horizontalSlider_speed, &QSlider::sliderMoved, this, &MainWindow::updateSliderValue);
}

void MainWindow::updateSliderValue()
{
    ui->label_speedValue->setText(QString::number(ui->horizontalSlider_speed->value()));
}

void MainWindow::updateConnectionDisplay(bool connected)
{
    if (connected){
        ui->label_connectionStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorGreen));
    } else {
        ui->label_connectionStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorRed));
    }
}

void MainWindow::updateErrorDisplay(bool resetAllErrors)
{
    if (resetAllErrors){
        ui->label_errorStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorGreen));
    } else {
        ui->label_errorStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorRed));
    }
}

void MainWindow::updateEStopDisplay(bool eStop)
{
    if (eStop){
        ui->label_eStopStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorRed));
    } else {
        ui->label_eStopStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorGreen));
    }
}

void MainWindow::updateRunningDisplay(bool running)
{
    if (running){
        ui->label_runningStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorGreen));
    } else {
        ui->label_runningStatus->setStyleSheet(QString("border-radius: 6px; background-color: %2").arg(colorGrey));
    }
}

