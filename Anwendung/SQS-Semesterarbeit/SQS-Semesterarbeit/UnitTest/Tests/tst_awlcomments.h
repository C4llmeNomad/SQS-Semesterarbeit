#ifndef TST_AWLCOMMENTS_H
#define TST_AWLCOMMENTS_H

#include <QObject>

#include "../testsuite.h"

class AwlCommentTest : public TestSuite
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();

    void singleLineComment_startOfLine();
};

#endif // TST_AWLCOMMENTS_H
