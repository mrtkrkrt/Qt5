#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaClassInfo>
#include <QTimer>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    QTimer *t = new QTimer(&parent);

    // make some children
    for(int i = 0; i < 5;i ++){
        test *t = new test(&parent);
        t->setObjectName("Child: " + QString::number(i));
    }

    foreach(QObject *c, parent.children()){
        qInfo() << c;
        qInfo() << c->metaObject()->className();
        qInfo() << "Inherits: " << c->inherits("test");

        for(int j = 0; j < c->metaObject()->methodCount(); j++){
            qInfo() << "Method: " << c->metaObject()->method(j).methodSignature();
        }
        qInfo("");
    }

    return a.exec();
}
