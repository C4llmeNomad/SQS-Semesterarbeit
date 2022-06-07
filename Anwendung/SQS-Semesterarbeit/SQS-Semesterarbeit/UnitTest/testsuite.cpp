#include "testsuite.h"

#include <QDebug>
#include <QTest>
#include <QStandardPaths>

QList<QObject *> *TestSuite::m_suites = nullptr;

TestSuite::TestSuite()
{
    static bool init = true;
    if(init){
        m_suites = new QList<QObject *>;
        init = false;
    }
    m_suites->append(this);
}

void TestSuite::executeTests()
{
    if(m_suites == nullptr){
        qDebug() << "No tests available";
        return;
    }

    int failedTests = 0;
    QList<QObject*>::iterator it = m_suites->begin();
    for(;it != m_suites->end(); it++){
        failedTests += QTest::qExec(*it);
    }
    qDebug() << "---------------------------------------";
    qDebug() << "Finished Testing";
    qDebug() << "Test Files: " << QString::number(m_suites->length());
    qDebug() << "Failed Tests: " << QString::number(failedTests);
    qDebug() << "---------------------------------------";

    if(failedTests != 0){
        exit(1);
    }
}
