#include "test.h"

test::test(QObject *parent)
    : QObject{parent}
{

}

void test::fill()
{
    m_name = "Test Object";
    for(int i = 0; i < 10; i++){
        QString num = QString::number(i);
        QString key = "Key: " + num;
        QString value = "This is item number: " + num;
        m_map.insert(key, value);
    }
}

QMap<QString, QString> test::get_map()
{
    return m_map;
}

void test::setName(QString name)
{
    m_name = name;
}

QString test::getName()
{
    return m_name;
}
