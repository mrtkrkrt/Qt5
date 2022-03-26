#ifndef LAPTOP_H
#define LAPTOP_H

#include <QObject>
#include <QDebug>

class laptop : public QObject
{
    Q_OBJECT
public:
    // Constructor
    explicit laptop(QObject *parent = nullptr, QString name = "");

    // Deconstructor
    // For Tilda Alt+0126 (For Turkish Q Keyboard)
    ~laptop();

    int weigth;
    QString name;
    double asKilogram();
    void test();

signals:

};

#endif // LAPTOP_H
