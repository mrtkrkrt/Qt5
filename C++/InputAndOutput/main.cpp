#include <QCoreApplication>
#include <QtDebug>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age;

    qInfo() << "Please enter an age : ";
    cin >> age;

    if(age < 0)
        qInfo() << "Your age => " << age;
    else
        cerr << "Error!!!";


    return a.exec();
}
