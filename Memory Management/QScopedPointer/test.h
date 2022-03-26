#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QScopedPointer>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);
    ~test();
signals:

};

#endif // TEST_H
