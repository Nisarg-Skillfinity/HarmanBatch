#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QThread>
#include <QDebug>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = 0);
    void DoSetup(QThread &cThread);
    QString name;
    bool stop = false;

signals:
    void NumberChanged(int i);

public slots:
    void DoWork();
};

#endif // MYOBJECT_H
