#include "test.h"

test::test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << " Constructed.";
}

test::~test()
{
    qInfo() << this << "Deconstruccted.";
}

void test::makeChild(QString name)
{
    test *child = new test();
    child->setObjectName(name);
}
