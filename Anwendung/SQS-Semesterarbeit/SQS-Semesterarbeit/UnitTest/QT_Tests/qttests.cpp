#include "qttests.h"

#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QString>
#include <QTextEdit>
#include <QtTest>

void QtGuiTest::initTestCase()
{
    MainWindow *mainWindow = new MainWindow();
    m_panel = mainWindow->window();

    m_panel->show();

    while ( !m_panel->isVisible() ) {
         QTest::qWait(200);
    }

    QTest::qWait(500);

    QVERIFY2(m_panel, "Window could not be crated");
}

void QtGuiTest::cleanupTestCase()
{
    m_panel->close();
    QTest::mouseMove(m_panel, QPoint(425, 300));
}

void QtGuiTest::testConnectButton()
{
    QPushButton *button = m_panel->findChild<QPushButton *>("pushButton_connect");
    QVERIFY2(button, "Connect Button not found");

    QTest::mouseMove(button, QPoint(20, 10));

    QTest::mouseClick(button, Qt::LeftButton, Qt::NoModifier, QPoint(20, 10));

    QTest::qWait(250);

    QLabel *connectionStatusLabel = m_panel->findChild<QLabel *>("label_connectionStatus");
    QVERIFY2(connectionStatusLabel, "Connect Status Label not found");
    QVERIFY2(connectionStatusLabel->styleSheet().contains("background-color: rgb(27, 193, 00)"), "Color of label_connectionStatus is not Green");
}

void QtGuiTest::testSlider()
{
    QSlider *slider = m_panel->findChild<QSlider *>("horizontalSlider_speed");
    QVERIFY2(slider, "Slider not found");

    QTest::mouseMove(slider, QPoint(0, 0));
    QTest::mousePress(slider, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    QTest::mouseMove(slider, QPoint(50, 0));
    QTest::mouseRelease(slider, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));

    QCOMPARE(slider->value(), 6);

    QLabel *speedLabel = m_panel->findChild<QLabel *>("label_speedValue");
    QVERIFY2(speedLabel, "Speed Label not found");
    QCOMPARE(speedLabel->text(), "6");
}

void QtGuiTest::testClearInput()
{
    QTextEdit *textField = m_panel->findChild<QTextEdit *>("textEdit_input");
    QVERIFY2(textField, "Input Field not found");

    QTest::mouseMove(textField, QPoint(50, 50));
    QTest::mouseClick(textField, Qt::LeftButton, Qt::NoModifier, QPoint(50, 50));

    QString testString = "test 123";
    QTest::keyClicks(textField, testString);
    QTest::qWait(50);
    QCOMPARE(textField->toPlainText(), testString);

    QPushButton *clearButton = m_panel->findChild<QPushButton *>("pushButton_clearInput");
    QVERIFY2(clearButton, "Clear Button not found");


    QTest::mouseMove(clearButton, QPoint(50, 10));
    QTest::mouseClick(clearButton, Qt::LeftButton, Qt::NoModifier, QPoint(50, 10));
    QTest::qWait(50);
    QCOMPARE(textField->toPlainText(), "");
}

void QtGuiTest::testDisconnect()
{
    // make sure we are connected via the GUI
    QLabel *connectionStatusLabel = m_panel->findChild<QLabel *>("label_connectionStatus");
    QVERIFY2(connectionStatusLabel, "Connect Status Label not found");
    if(!connectionStatusLabel->styleSheet().contains("background-color: rgb(27, 193, 00)")){
        testConnectButton();
    }

    QTextEdit *textField = m_panel->findChild<QTextEdit *>("textEdit_input");
    QVERIFY2(textField, "Input Field not found");

    QTest::mouseMove(textField, QPoint(50, 50));
    QTest::mouseClick(textField, Qt::LeftButton, Qt::NoModifier, QPoint(50, 50));

    QString inputString = "disconnect";
    QTest::keyClicks(textField, inputString);
    QTest::qWait(50);
    QCOMPARE(textField->toPlainText(), inputString);

    QPushButton *startButton = m_panel->findChild<QPushButton *>("pushButton_start");
    QVERIFY2(startButton, "Start Button not found");
    QTest::mouseMove(startButton, QPoint(50, 10));
    QTest::mouseClick(startButton, Qt::LeftButton, Qt::NoModifier, QPoint(50, 10));

    QTest::qWait(50);
    QVERIFY2(connectionStatusLabel->styleSheet().contains("background-color: rgb(203, 47, 47)"), "Color of label_connectionStatus is not Red");

    textField->clear();
}

void QtGuiTest::testErrorInput()
{
    // make sure we are connected via the GUI
    QLabel *connectionStatusLabel = m_panel->findChild<QLabel *>("label_connectionStatus");
    QVERIFY2(connectionStatusLabel, "Connect Status Label not found");
    if(!connectionStatusLabel->styleSheet().contains("background-color: rgb(27, 193, 00)")){
        testConnectButton();
    }

    QTextEdit *textField = m_panel->findChild<QTextEdit *>("textEdit_input");
    QVERIFY2(textField, "Input Field not found");

    QTest::mouseMove(textField, QPoint(50, 50));
    QTest::mouseClick(textField, Qt::LeftButton, Qt::NoModifier, QPoint(50, 50));

    QString inputString = "error";
    QTest::keyClicks(textField, inputString);
    QTest::qWait(50);
    QCOMPARE(textField->toPlainText(), inputString);

    QPushButton *startButton = m_panel->findChild<QPushButton *>("pushButton_start");
    QVERIFY2(startButton, "Start Button not found");
    QTest::mouseMove(startButton, QPoint(50, 10));
    QTest::mouseClick(startButton, Qt::LeftButton, Qt::NoModifier, QPoint(50, 10));

    QTest::qWait(50);
    QLabel *errorStatusLabel = m_panel->findChild<QLabel *>("label_errorStatus");
    QVERIFY2(errorStatusLabel, "Connect Status Label not found");
    QVERIFY2(errorStatusLabel->styleSheet().contains("background-color: rgb(203, 47, 47)"), "Color of label_errorStatus is not Red");

    QPushButton *resetButton = m_panel->findChild<QPushButton *>("pushButton_resetErrorAndEStop");
    QVERIFY2(resetButton, "Reset Button not found");
    QTest::mouseMove(resetButton, QPoint(50, 10));
    QTest::mouseClick(resetButton, Qt::LeftButton, Qt::NoModifier, QPoint(50, 10));

    QTest::qWait(50);
    QVERIFY2(errorStatusLabel->styleSheet().contains("background-color: rgb(27, 193, 00)"), "Color of label_errorStatus is not Green");

    textField->clear();
}

static QtGuiTest instance;
