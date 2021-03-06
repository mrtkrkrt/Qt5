#include <QCoreApplication>
#include "test.h"

// The QScopedPointer class stores a pointer dynamically allocates object,
// and deletes it upon detruction!!!

void mytest(QScopedPointer<test> &mypointer) {
    qInfo() << mypointer.data();
}

void useit(test* obj) {
    if(!obj) return;

    qInfo() << "Using" << obj;
}

void doStuff() {
    //test *t = new test(); // dangling pointer!!!
    QScopedPointer<test> mypointer(new test());

    useit(mypointer.data());
    mytest(mypointer);

    //pointer is automatically deleted!!!
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    for(int i = 0; i < 100; i++) {
        doStuff();
    }

    doStuff();

    return a.exec();
}
