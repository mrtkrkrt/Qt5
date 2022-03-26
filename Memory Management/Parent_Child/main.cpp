#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test *p = new test(&a); // should not be a nullptr

    p->setObjectName("parent");

    for (int i = 0; i < 3; i++) {
        p->makeChild("child");
    }

    delete p;

    return a.exec();
}
