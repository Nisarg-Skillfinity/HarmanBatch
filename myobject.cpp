#include "myobject.h"

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::DoSetup(QThread &cThread)
{
    connect(&cThread, SIGNAL(started()), this, SLOT(DoWork()));
}

void MyObject::DoWork()
{
    for(int i = 0; i < 10000; i++)
    {
        if(stop)
        {
            break;
        }
        emit NumberChanged(i);
        QThread::msleep(100);
    }
}
