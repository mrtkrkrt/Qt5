#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *obj = new QObject(nullptr); // we  actually do not use nullptr this is just for illustration

    obj->setObjectName("My Object");
    QPointer<QObject> p(obj);

    test t;
    t.widget = p;
    t.testPointer();

    if(p.data()) qInfo() << p.data();

    delete p;
    t.testPointer();

    return a.exec();
}
