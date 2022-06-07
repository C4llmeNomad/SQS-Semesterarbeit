#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>

/**
 * @brief The TestSuite class execute all defined tests and reports if they were successful or not.
 * Tests have the following layout:
 *
        #include "testsuite.h"

        class MyTestName : public TestSuite
        {
            Q_OBJECT
        private:
            void initTestCase();
            void cleanupTestCase();

            void test1();
            void test2();
        };

        // Register the test at the testsuite
        static AwlParserTest instance;
*/

class TestSuite : public QObject
{
    Q_OBJECT
public:
    explicit TestSuite();
    static void executeTests();

private:
    static QList<QObject*> *m_suites;

};

#endif // TESTSUITE_H
