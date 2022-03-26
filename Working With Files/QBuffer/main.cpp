#include <QCoreApplication>
#include <QBuffer>
#include <QIODevice>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer qBuffer;

    if(qBuffer.open(QIODevice::ReadWrite)){
        qInfo() << "Buffer Opened.";

        QByteArray data("Hello World");

        for (int i = 0; i < 5; i++) {
            qBuffer.write(data);
        }
        // File and device may access you may need to flush the data to the device
        // buffer.flush()

        // Move to the first position
        qBuffer.seek(0);

        qInfo() << qBuffer.readAll();
        qInfo() << "Buffer closing.";

        qBuffer.close();
    }else{
        qInfo() << "Buffer could not open!";
    }

    return a.exec();
}
