#include <QCoreApplication>
#include "destination.h"
#include "source.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    destination dest;
    source objSource;

    QObject::connect(&objSource, &source::mySignal, &dest, &destination::onMessage);

    objSource.test();

    return a.exec();
}
