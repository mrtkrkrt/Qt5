#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QBuffer>
#include <QTextStream>

// Our own custom file format, will not work anything else!!!

bool makeFile(QString path){

    QFile file(path);

    if(file.open(QIODevice::WriteOnly)){

        QByteArray data;

        for(int i = 0; i < 1000; i++){
            data.append(QString::number(i) + "\r\n");
        }

        file.write(data);

        file.close();
        return true;
    }

    return false;
}

QByteArray getHeader(){
    QByteArray header;
    header.append("@!~!@");
    return header;
}

bool compressFile(QString originalFile, QString newFile){
    QFile oFile(originalFile);
    QFile nFile(newFile);

    if(!oFile.open(QIODevice::ReadOnly)) return false;
    if(!nFile.open(QIODevice::WriteOnly)) return false;

    int size = 1024;

    while(!oFile.atEnd()){
        QByteArray buffer = oFile.read(size);
        QByteArray compressed = qCompress(buffer);
        qInfo() << "Header at: " << nFile.pos();
        nFile.write(getHeader());
        nFile.write(compressed);
    }

    nFile.close();
    oFile.close();
}

bool deCompressFile(QString originalFile, QString newFile){
    QFile oFile(originalFile);
    QFile nFile(newFile);

    if(!oFile.open(QIODevice::ReadOnly)) return false;
    if(!nFile.open(QIODevice::WriteOnly)) return false;

    int size = 1024;

    //Double check that WE compressed the file
    QByteArray buffer = oFile.peek(size);
    if(!buffer.startsWith(header)) {
        qCritical() << "We did not create this file!";
        oFile.close();
        nFile.close();
        return false;
    }

    //Find the header positions
    oFile.seek(header.length());
    qInfo() << "Starting at: " << oFile.pos();

    while (!oFile.atEnd()) {
        buffer = oFile.peek(size);
        qint64 index = buffer.indexOf(getHeader());
        qInfo() << "Header found at:" << index;

        if(index > -1) {
            //Have the header!
            qint64 maxbytes = index;
            qInfo() << "Reading: " << maxbytes;
            buffer = oFile.read(maxbytes);
            oFile.read(getHeader().length());
        } else {
            //Do not have the header!
            qInfo() << "Read all, no header";
            buffer = oFile.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        qInfo() << "Decompressed: " << nFile.write(decompressed);
        nFile.flush();
    }

    oFile.close();
    nFile.close();

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString orginalFile = QDir::currentPath() + QDir::separator() + "orginal.txt";
    QString compressedFile = QDir::currentPath() + QDir::separator() + "compressed.txt";
    QString decompressedFile = QDir::currentPath() + QDir::separator() + "decompressed.txt";

    if(makeFile(orginalFile)) {
        qInfo() << "Original created";

        if(compressFile(orginalFile, compressedFile)) {
            qInfo() << "File compressed";
        } else {
            qInfo() << "File not compressed";
        }
    }

    return a.exec();
}
