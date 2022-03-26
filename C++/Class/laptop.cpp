#include "laptop.h"

laptop::laptop(QObject *parent, QString name)
    : QObject{parent}
{
    // When created - "this" is automaticallly created
    this->name = name;
    qInfo() << this << name << " constructed ";
}

laptop::~laptop()
{
    // When destroyed
    qInfo() << this << name << " destroyed ";
}

double laptop::asKilogram()
{
    return this->weigth * 0.45896;
}

void laptop::test()
{
    qDebug() << this << name << asKilogram();
}
