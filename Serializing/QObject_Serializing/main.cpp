#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>

bool saveFile(QString path){
    QFile file(path);

    if(file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);

    QString title = "This is title!!!";
    qint64 num = 64;

    out << title;
    out << num;

    // after writing out might be flush but I need guarantee

    file.flush();
    file.close();

    return true;
}

bool readFile(QString path){
    QFile file(path);

    if(file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);

    if(in.version() != QDataStream::Qt_5_15){
        qCritical() << "Bad Version!";
        file.close();
        return false;
    }

    QString title;
    quint64 num;

    in >> title;
    in >> num;

    qInfo() << title;
    qInfo() << num;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";

    if(saveFile(path)){
        qInfo() << "Saved!";
        readFile(path);
    }

    return a.exec();
}
