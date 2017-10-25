#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QDebug>

#include <QDir>
//#include <unistd.h>
#include <QThread>
#include <iostream>

QFileInfoList GetFileList(QString path)//得到所有文件名称（包括路径）
{
    QDir dir(path);
    //列出dir(path)目录文件下所有文件和目录信息，存储到file_list容器
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    //列出dir(path)目录下所有子文件夹
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    //进行子文件夹folder_list遍历，将内容存入file_list容器
    //qDebug() << folder_list.size() << "\n";

    for(int i= 0; i != folder_list.size(); i++)
    {
        QString name = folder_list.at(i).absoluteFilePath();
        //qDebug() << name;
        QFileInfoList child_file_list = GetFileList(name);
        file_list.append(child_file_list);//获取子文件夹的文件
    }
    std::cout << file_list.size();
    return file_list;
}
void delSame(QString sourceDir, QString toDir)//从to中找到source中的文件，然后删除
{
    QFileInfoList sourceDirList = GetFileList(sourceDir);
    QFileInfoList toDirList = GetFileList(toDir);
    for (int i = 0; i < sourceDirList.size(); i++)
    {
        QFileInfo sourceFileInfo = sourceDirList.at(i);
        QString sourceName = sourceFileInfo.fileName();
        for(int j = 0; j < toDirList.size(); j++)
        {
            QFileInfo toFileInfo = toDirList.at(j);
            QString toAbsPath = toFileInfo.absoluteFilePath();
            QString toName = toFileInfo.fileName();
            if (sourceName == toName){
                QString tempName = toAbsPath;
                QFile tempFile(tempName);
                qDebug() << tempName << "/n";
                tempFile.remove();
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString sourceDir = "C:\\Users\\YoungMagic\\Desktop\\output\\my\\test2\\";
    QString toDir = "C:\\Users\\YoungMagic\\Desktop\\output\\my\\test1\\";
    delSame(sourceDir, toDir);
   // QString test= "";
    //GetFileList(test);

    system("pause");
    return 0;
}
