#include <QCoreApplication>
#include <QDebug>
#include "test.h"

template<typename T>
void print(T value) {
    qInfo() << value;
}

template<class T, class F>
T add(T value1, F value2) {
    return value1 + value2;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    print<int>(1);
    print<double>(126.007);
    print<QString>("Hello world!");

    test<int> intCalc;
    qInfo() << intCalc.add(1,4);

    test<double> doubleCalc;
    qInfo() << doubleCalc.add(1.09,0.075);

    test<QString> stringCalc;
    qInfo() << stringCalc.add("Hello ", "World");



    return a.exec();
}
