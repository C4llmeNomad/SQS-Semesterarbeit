#ifndef CSVCONFIGWRITER_H
#define CSVCONFIGWRITER_H


#include <QFileInfo>
#include <QString>


/**
 * @brief The CSVConfigWriter class: writes the relevant PLC settings into a CSV File
 */
class CSVConfigWriter :  public QObject
{
    Q_OBJECT

public:
    /**
     * @brief CSVConfigWriter: Constructor
     * @param filePath: Path for the .csv file
     */
    CSVConfigWriter(QFileInfo filePath);

    /**
     * @brief Destructor
     */
    ~CSVConfigWriter();

public slots:
    /**
     * @brief writeFile: write all relevant settings from m_config to the CSV File
     * and renames the old CSV File
     */
    void writeFile();

private:
    QString m_filePath;
};

#endif // CSVCONFIGWRITER_H
