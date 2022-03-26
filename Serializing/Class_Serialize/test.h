#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QDataStream>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    void fill();
    QMap<QString, QString> get_map();
    void setName(QString name);
    QString getName();

    friend QDataStream& operator <<(QDataStream &stream, const test &t){
        qInfo() << "Operload";
        stream << t.m_name;
        stream << t.m_map;
        return stream;
    }

    friend QDataStream& operator >>(QDataStream &stream, test &t){
        qInfo() << "Operload";
        stream >> t.m_name;
        stream >> t.m_map;
        return stream;
    }

private:
    QString m_name;
    QMap<QString, QString> m_map;

signals:

};

#endif // TEST_H
