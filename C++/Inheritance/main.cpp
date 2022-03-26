#include <QCoreApplication>
#include "feline.h"
#include "canine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //we know about this because its included!
    //animal test;

    feline kitty;

    //canine puppy;


    return a.exec();
}
