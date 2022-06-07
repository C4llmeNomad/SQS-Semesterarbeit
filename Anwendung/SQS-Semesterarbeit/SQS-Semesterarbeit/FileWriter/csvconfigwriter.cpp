#include "csvconfigwriter.h"

#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>
#include <QStandardPaths>
#include <QTextStream>


CSVConfigWriter::CSVConfigWriter(QFileInfo filePath)
{
   // m_filePath = Files::checkFilePathAndName(filePath.absoluteFilePath(), m_filePath, {".csv"}, "config.csv");
}
CSVConfigWriter::~CSVConfigWriter()
{
}


void CSVConfigWriter::writeFile()
{

    QFile outdatedFile(m_filePath + ".old");
    outdatedFile.remove();

    QFileInfo oldCSVInfo(m_filePath);
    if(oldCSVInfo.exists() && oldCSVInfo.isFile()){
        QFile oldCSVFile(m_filePath);
        oldCSVFile.rename(m_filePath + ".old");
    }

    QFile newCSVFile(m_filePath);
    if(newCSVFile.open(QFile::WriteOnly)) {
        QTextStream output(&newCSVFile);
       // output << m_config.toString();
    }
    else {
        qDebug() << "Can not open file: " << m_filePath;
    }
    newCSVFile.close();
}

