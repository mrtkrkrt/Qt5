#include <QCoreApplication>
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "File: " << logger::filename;
    logger::attach();

    qInfo() << "test!";

    logger::logging = false;
    qInfo() << "Don't log this!";
    logger::logging = true;

    qInfo() << "Finished!";

    return a.exec();
}
