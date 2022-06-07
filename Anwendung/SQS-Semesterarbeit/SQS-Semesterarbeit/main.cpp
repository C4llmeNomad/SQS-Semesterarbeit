#include "main.h"
#include "mainwindow.h"
#include "UnitTest/testsuite.h"

#include <QApplication>
#include <QMessageBox>
#include <QLockFile>
#include <QDir>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Check for lock file
    QLockFile lockFile(QDir::temp().absoluteFilePath("SQS-Semesterarbeit.lock"));
    if(checkIfAlreadyRunning(lockFile)){
        return -1;
    }

    // Set application details (Important for QSettings)
    QString mode = parseModeFromCommandLine(&app);
    QApplication::setApplicationName("SQS-Semesterarbeit-" + mode);
    QApplication::setApplicationVersion(QString(GIT_VERSION));



    // Run tests if in debug mode
#ifdef QT_DEBUG
    TestSuite::executeTests();
#endif
    // Show main window
    MainWindow window;
    window.show();
    int returnCode = app.exec();
    return returnCode;
}

bool checkIfAlreadyRunning(QLockFile& lock)
{
    if(!lock.tryLock(100)){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Application is already running");
        msgBox.exec();
        return true;
    }
    return false;
}


QString parseModeFromCommandLine(QApplication* app)
{
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    // Add mode option
    QStringList mode{"m", "mode"};
    QStringList modeOptions{"production", "research", "develop"};
    QString optionDesc = QString("One of [%1]").arg(modeOptions.join(","));
    QCommandLineOption applicationMode(mode, optionDesc, modeOptions.at(0));
    parser.addOption(applicationMode);

    // Process the actual command line arguments given by the user
    parser.process(*app);

    QString profile = parser.value(applicationMode).toLower();
    bool validMode = modeOptions.contains(profile);
    return validMode ? profile : modeOptions.at(0);
}
