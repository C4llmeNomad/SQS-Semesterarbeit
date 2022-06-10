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

private:
    QWidget *m_panel;
};

#endif // QT_TESTS_H
