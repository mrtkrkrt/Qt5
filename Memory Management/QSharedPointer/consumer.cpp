#include "consumer.h"

consumer::consumer(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed.";
}

consumer::~consumer()
{
    qInfo() << this << "Deconstructed.";
}
