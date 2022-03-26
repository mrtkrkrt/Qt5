#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QPointer>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    QPointer<QObject> widget;

    void testPointer();
signals:

};

#endif // TEST_H
