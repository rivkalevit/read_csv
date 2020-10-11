//rivush:)

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QHash>
#include <QString>
#include <QStringList>
#include <QDebug>

static QFile file;
static QHash <QString,QString> permission_hash;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString fileName = "D:/rivka_work/docs/permissions.csv";
    QStringList st_list;
    QString name;
    QString password;


    file.setFileName(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        qDebug("%s.%d open failed",__FUNCTION__,__LINE__);
        return 0;
    }

    QTextStream in(&file);
    while (!in.atEnd()){
       QString line = in.readLine();
       st_list = line.split(",");
       if(st_list.at(0) == "שם משתמש")
           continue;
       permission_hash[st_list.at(0)] = st_list.at(1);
    }
    file.close();


    password = permission_hash["רותם"];
    password = permission_hash["רבקה"];
    password = permission_hash["מיכל"];
    password = permission_hash["נחמה"];
    password = permission_hash["ממ"];

    int x;
    x++;

    return a.exec();
}
