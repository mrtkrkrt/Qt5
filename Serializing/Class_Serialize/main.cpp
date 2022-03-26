#include <QCoreApplication>
#include<QDir>
#include "test.h"

bool saveFile(test *t, QString path){
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);
    //ds << t->getName();
    // ds << t->get_map();
    out << *t;

    file.close();
    return true;
}

bool loadFile(QString path) {
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);
    test t;
    in >> t;

    file.close();

    qInfo() << "Name: " << t.getName();
    foreach(QString key, t.get_map().keys()){
        qInfo() << key << " : " << t.get_map().value(key);
    }

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";

    test t;
    t.fill();
    if(saveFile(&t,path)) {
        loadFile(path);
    }

    return a.exec();
}
