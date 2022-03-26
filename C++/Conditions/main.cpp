#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age = 0;
    qInfo() << "Please enter your age : ";
    cin >> age;

    age = (age < 18) ? 0 : age;

    if(age == 0) qFatal("You can not enter.");

    qInfo() << "Your age: " << age;

    if(age < 21 && age >= 18) qInfo() << "You are not really adult.";
    else if(age >= 21) qInfo() << "You are an adult";

    if(age > 120) qInfo() << "You are really old";

    qInfo() << "Program Finished";
    return a.exec();
}
