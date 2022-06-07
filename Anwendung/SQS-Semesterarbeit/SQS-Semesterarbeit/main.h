#ifndef MAIN_H
#define MAIN_H

#include <QString>

class QApplication;
class QLockFile;


/**
 * @brief checkIfAlreadyRunning: Check if there is already a running instance of DVM_CUP
 * @param lock: Lockfile instance
 * @return True if there is already an instance
 */
bool checkIfAlreadyRunning(QLockFile &lock);

/**
 * @brief parseModeFromCommandLine: Parse the commandline arguments for a valid mode selection
 * @param app: Application instance of the DVM_CUP
 * @return: One of the three modes: "production" (default), "research", "develop"
 */
QString parseModeFromCommandLine(QApplication* app);

#endif // MAIN_H
