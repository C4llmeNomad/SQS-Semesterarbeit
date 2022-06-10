#ifndef QT_TESTS_H
#define QT_TESTS_H

#include <QObject>
#include <QWidget>

#include <SQS-Semesterarbeit/mainwindow.h>

#include "../testsuite.h"

class QtGuiTest : public TestSuite
{
    Q_OBJECT

friend class MainWindow;


private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();

    void testConnectButton();
    void testSlider();
    void testClearInput();
    void testDisconnect();
    void testErrorInput();
    void testRandomInput();

private:
    /**
     * @brief establishConnection: verifies that the machine is connected using the GUI
     * @return true if there is a established connection, otherwise false
     */
    bool establishConnection();

    /**
     * @brief connectedAndRunning: Checks if the Machine is connected and running
     * For Integrity it is also verified that there are no active errors or
     * that the emergency stop is activated
     * @return true if the machine is connected and running, otherwise false
     */
    bool connectedAndRunning();

private:
    QWidget *m_panel;
};

#endif // QT_TESTS_H
