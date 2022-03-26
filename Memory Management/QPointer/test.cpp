#include "test.h"

test::test(QObject *parent)
    : QObject{parent}
{

}

void test::testPointer()
{
    // see if there is a pointer
    if(!widget.data()){
        qInfo() << "Pointer does not exist!!!"; // No pointer
        return;
    }

    // widget.data()->setObjectName("My QPointer");
    qInfo() << widget.data();
    widget.data()->setObjectName("My QPointer");
}
