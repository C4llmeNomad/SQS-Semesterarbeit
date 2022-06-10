#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initStatusDisplay();
    initMachineControl();
    initSpeedSlider();
    initInputField();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initStatusDisplay()
{
    m_machineControl = new MachineControl();

    ui->label_connectionStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorRed));
    connect(m_machineControl, &MachineControl::connected, this, &MainWindow::updateConnectionDisplay);


    ui->label_errorStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorGreen));
    connect(m_machineControl, &MachineControl::resetAllErrors, this, &MainWindow::updateErrorDisplay);
    connect(m_machineControl, &MachineControl::resetEStop, this, &MainWindow::updateEStopDisplay);

    ui->label_eStopStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorGreen));
    connect(m_machineControl, &MachineControl::eStopActivated, this, &MainWindow::updateEStopDisplay);

    ui->label_runningStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorGrey));
    connect(m_machineControl, &MachineControl::machineRunning, this, &MainWindow::updateRunningDisplay);
}

void MainWindow::initMachineControl()
{
    connect(ui->pushButton_start, &QPushButton::pressed, this, &MainWindow::startMachine);

    connect(ui->pushButton_stop, &QPushButton::pressed, m_machineControl, &MachineControl::emergencyStop);

    connect(ui->pushButton_connect, &QPushButton::pressed, m_machineControl, &MachineControl::connect);

    connect(ui->pushButton_resetErrorAndEStop, &QPushButton::pressed, m_machineControl, &MachineControl::resetErrorAndEStop);
}

void MainWindow::initSpeedSlider()
{
    ui->label_speedValue->setText(QString::number(ui->horizontalSlider_speed->value()));
    connect(ui->horizontalSlider_speed, &QSlider::valueChanged, this, &MainWindow::updateSliderValue);
}

void MainWindow::updateSliderValue()
{
    ui->label_speedValue->setText(QString::number(ui->horizontalSlider_speed->value()));
}

void MainWindow::updateConnectionDisplay(bool connected)
{
    if (connected){
        ui->label_connectionStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorGreen));
    } else {
        ui->label_connectionStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorRed));
    }
}

void MainWindow::updateErrorDisplay(bool resetAllErrors)
{
    if (resetAllErrors){
        ui->label_errorStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorGreen));
    } else {
        ui->label_errorStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorRed));
    }
}

void MainWindow::updateEStopDisplay(bool eStopActivated)
{
    if (eStopActivated){
        ui->label_eStopStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorRed));
    } else {
        ui->label_eStopStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorGreen));
    }
}

void MainWindow::updateRunningDisplay(bool running)
{
    if (running){
        ui->label_runningStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorGreen));
    } else {
        ui->label_runningStatus->setStyleSheet(QString("border-radius: 6px; background-color: %1").arg(colorGrey));
    }
}

void MainWindow::startMachine()
{
    m_machineControl->startMachine();

    processInput(ui->textEdit_input->toPlainText().toLower());
}

void MainWindow::initInputField()
{
    connect(ui->pushButton_clearInput, &QPushButton::pressed, this, [this] {ui->textEdit_input->clear();});
}

void MainWindow::processInput(QString input)
{
    if (input.contains("error")){
        m_machineControl->error();
    }
    if (input.contains("disconnect")){
        m_machineControl->disconnect();
    }
}
