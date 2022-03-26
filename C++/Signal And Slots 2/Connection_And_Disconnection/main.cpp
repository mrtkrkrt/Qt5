#include <QCoreApplication>
#include <QtDebug>
#include <QTextStream>
#include <iostream>
#include "radio.h"
#include "station.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    radio boombox;
    station* channels[3];

    // create some stations
    channels[0] =  new station(&boombox, "Rock And Roll", 94);
    channels[1] =  new station(&boombox, "Hip Hop", 101);
    channels[2] =  new station(&boombox, "Pop", 85);

    // QueuedConnection => used when you wprk with threads
    boombox.connect(&boombox, &radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    do{
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtin(stdin);
        QString line = qtin.readLine().trimmed().toLower();

        if(line == "on"){
            qInfo() << "Radio is on!";
            for (int i = 0; i < 3; i++) {
                station* temp = channels[i];
                temp->connect(temp, &station::send, &boombox, &radio::listen);
            }
        }else if(line == "off"){
            qInfo() << "Radio is off!";
            for (int i = 0; i < 3 ; i++) {
                station* temp = channels[i];
                temp->disconnect(temp, &station::send, &boombox, &radio::listen);
            }
        }else if(line == "test"){
            qInfo() << "Testing!";
            for(int i = 0; i < 3; i++) {
                station* temp = channels[i];
                temp->broadcast("Broadcasting live!");
            }
        }else if(line == "quit"){
            qInfo() << "Quitting!";
            emit boombox.quit();
            break;
        }else{
            qInfo() << "Wrong Input!!!";
        }
    }while(true);

    return a.exec();
}
