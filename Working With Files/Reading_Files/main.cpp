#include <QCoreApplication>
#include <QIODevice>
#include <QDir>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QTextStream>

bool write(QString path, QByteArray data){
    QFile file(path);

    if(file.open(QIODevice::WriteOnly)){
        qint64 bytes = file.write(data);
        if(bytes) return true;
        return false;
    }

    qWarning() << file.errorString();

    return false;
}

bool createFile(QString path){
    QByteArray data;
    for(int i = 0; i < 5; i++) {
        data.append(QString::number(i));
        data.append(" Hello World\r\n");
    }

    return write(path,data);
}

void readFile(QString path){
    QFile file(path);

    if(!file.exists()){
        qWarning() << "File not found!!!";
        return;
    }

    if(!file.open(QIODevice::ReadOnly)){
        qWarning() << file.errorString();
        return;
    }

    qInfo() << "Reading File";
    qInfo() << file.readAll(); // Best for small files!
    qInfo() << "Reading Done!";

}

void readLines(QString path){
    QFile file(path);

    if(file.exists()){
        if(file.open(QIODevice::ReadOnly)){
            qInfo() << "Reading File";
            while(!file.atEnd()){
                QString line(file.readLine().trimmed());
                qInfo() << line; // Best for text files
            }
            qInfo() << "Readin Done!";
        }else{
            qWarning() << file.errorString();
        }
    }else{
        qWarning() << "File not found!";
    }
}

void readBytes(QString path){
    QFile file(path);

    if(file.exists()){
        if(file.open(QIODevice::ReadOnly)){
            qInfo() << "Reading File";
            while(!file.atEnd()){
                qInfo() << file.read(10); // Best for larger files or structs
            }
            qInfo() << "Readin Done!";
        }else{
            qWarning() << file.errorString();
        }
    }else{
        qWarning() << "File not found!";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
