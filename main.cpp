#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include "myobject.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QThread cThread;
//    QThread cThread_2;
//    MyObject cObject;
//    MyObject cObject_2;

//    cObject.name = "cObject";
//    cObject.DoSetup(cThread);
//    cObject.moveToThread(&cThread);

//    cObject_2.name = "cObject2";
//    cObject_2.DoSetup(cThread_2);
//    cObject_2.moveToThread(&cThread_2);

//    cThread.start();
//    cThread_2.start();

    return a.exec();
}
