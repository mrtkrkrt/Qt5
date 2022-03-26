#ifndef ANIMAL_H // if not defined
#define ANIMAL_H // define it

#include <QObject>
#include <QDebug>

class Animal : public QObject
{
    Q_OBJECT
    // here is private
public:
    explicit Animal(QObject *parent = nullptr);
    void speak(QString message);
signals:

public slots:
};

#endif // ANIMAL_H
