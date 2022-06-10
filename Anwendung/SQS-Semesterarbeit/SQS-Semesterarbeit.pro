###################################################################
GIT_VERSION = $$system(git describe --long --always --dirty)
GIT_BRANCH  = $$system(git rev-parse --abbrev-ref HEAD)
GIT_BRANCH  = $$replace(GIT_BRANCH,$$LITERAL_HASH,_) #hashtags break everythign in qmake
DEFINES += GIT_VERSION=\\\"$$GIT_VERSION\\\"
DEFINES += GIT_BRANCH=\\\"$$GIT_BRANCH\\\"


QMAKE_TARGET_PRODUCT = SQS-Semesterarbeit
QMAKE_TARGET_DESCRIPTION = $$QMAKE_TARGET_PRODUCT $$GIT_VERSION
###################################################################

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# Do not use -g in debug mode as the compiled program does not start
QMAKE_CXXFLAGS_DEBUG -= -g
QMAKE_CXXFLAGS_DEBUG *= -O1

# Testlib makes debug console appear on program execution. Not wanted for deployed stables.
CONFIG(debug, debug|release): QT += testlib

# Warn if Qt feature that is marked as deprecated is used
DEFINES += QT_DEPRECATED_WARNINGS


# Windows specific
win32:LIBS += -lKernel32
win32:RC_ICONS += Resources/application.ico


# Copy required libraries to build dir
# Requires execution of "make install" in the build chain
CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug


SOURCES += \
    SQS-Semesterarbeit/main.cpp \
    SQS-Semesterarbeit/filewriter.cpp \
    SQS-Semesterarbeit/machinecontrol.cpp \
    SQS-Semesterarbeit/mainwindow.cpp \




CONFIG(debug, debug|release): \
    SOURCES += \
        SQS-Semesterarbeit/UnitTest/testsuite.cpp \
        SQS-Semesterarbeit/UnitTest/QT_Tests/qttests.cpp \


HEADERS += \
    SQS-Semesterarbeit/filewriter.h \
    SQS-Semesterarbeit/machinecontrol.h \
    SQS-Semesterarbeit/mainwindow.h \


CONFIG(debug, debug|release): \
    HEADERS  +=    \
        SQS-Semesterarbeit/UnitTest/testsuite.h \
        SQS-Semesterarbeit/UnitTest/QT_Tests/qttests.h \


FORMS += \
    SQS-Semesterarbeit/mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
