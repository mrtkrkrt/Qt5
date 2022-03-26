#include <QCoreApplication>
#include <iostream>
#include <QDebug>

using namespace std;

struct laptop {
    int weight;

    double asKilograms() {
        return weight * 0.453592;
    }
};

//Pass by value - COPY
void testVal(int x) {
    x = x * 10;
    qInfo() << "x = " << x;
}

//Pass by Ref - NOT A COPY
void testRef(int &y) {
    y = y * 10;
    qInfo() << "y = " << y;
}

bool isPrime(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

void test(int age = 0) { //testAge
    qInfo() << "You are " << age << " years old.";
}

void test(bool isActive) { // testBool
    qInfo() << "testing";

    if(isActive)
    {
        qInfo() << "It is active";
    } else {
        qInfo() << "NOT ACTIVE";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
