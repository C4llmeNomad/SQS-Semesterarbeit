#include "tst_awlcomments.h"

#include <QDebug>
#include <QString>
#include <QtTest>

void AwlCommentTest::initTestCase(){}

void AwlCommentTest::cleanupTestCase(){}

void AwlCommentTest::singleLineComment_startOfLine()
{
    QStringList commands;
    commands << "a";
    commands << "//b";
    commands << "c";

    QStringList expected;
    expected << "dub";

    QStringList created;
    created << "dub";
    QCOMPARE(created, expected);
}

static AwlCommentTest instance;
