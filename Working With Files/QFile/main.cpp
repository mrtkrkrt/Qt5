#include <QCoreApplication>
#include <QIODevice>
#include <QDir>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>

bool put(QString path, QByteArray data, QIODevice::OpenMode mode){
    QFile file(path);

    if(!file.open(mode)){
        qWarning() << file.errorString();
        return false;
    }

    qint64 bytes = file.write(data);

    if(bytes > 0){
        qWarning() << file.errorString();
    } else {
        qInfo() << "Wrote " << bytes << " to the file!";
    }

    file.flush();
    file.close();

    return true;
}

void write(QString path, QByteArray data){
    QFile file(path);

    if(file.open(QIODevice::WriteOnly)){
        file.write(data);
        qInfo() << "Wrote!!!";
    }else{
        qInfo() << "Could not write!";
    }
}

void append(QString path, QByteArray data){
    QFile file(path);

    if(file.open(QIODevice::Append)){
        file.write(data);
        qInfo() << "Wrote!!!";
    }else{
        qInfo() << "Could not open!";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    qInfo() << "Path: " << path;

    QByteArray data("Hello World!\r\n");

    for(int i = 0; i < 5; i++) {
        QString num = QString::number(i);
        num.append(" ");

        QByteArray line(num.toLatin1() + data);
        write(path,line);
        //append(path,line);
    }

    return a.exec();
}
