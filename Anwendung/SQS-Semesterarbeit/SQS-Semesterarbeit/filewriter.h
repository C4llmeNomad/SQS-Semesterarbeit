#ifndef FILEWRITER_H
#define FILEWRITER_H


#include <QFileInfo>
#include <QString>


/**
 * @brief The CSVConfigWriter class: writes the relevant PLC settings into a CSV File
 */
class FileWriter :  public QObject
{
    Q_OBJECT

public:
    /**
     * @brief CSVConfigWriter: Constructor
     * @param filePath: Path for the .csv file
     */
    FileWriter(QFileInfo filePath);

    /**
     * @brief Destructor
     */
    ~FileWriter();

public slots:
    /**
     * @brief writeFile: write all relevant settings from m_config to the CSV File
     * and renames the old CSV File
     */
    void writeFile();

private:
    QString m_filePath;
};

#endif // FILEWRITER_H
