#include <QCoreApplication>
#include <QDebug>

void test(QString name){
    // Working with stack
    qDebug() << "Size = " << name.length();
}

void testPtr(QString* name){
    // Working with heap
    qDebug() << "Size = " << name->length();
}

void display(QString* value){
    qDebug() << "The pointer : " << value;
    qDebug() << "The object : " << &value << " A copy of the pointer!!";
    qDebug() << "The Data : " << *value;
    qInfo("");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Stack is very limited amount of memory. Heap ia as much memory you want.
    // Use stack for stack as a manage location.

    QString name = "Murat"; // Called QString constructor here
    QString* description = new QString("Hello World");

    test(name);
    testPtr(&name);

    qInfo() << "Name len = " << name.length();
    qInfo() << "Description len = " << description->length();

    display(description);
    display(&name);

    delete description; // = 0

    // Called QString deconstructor here

    return a.exec();
}
