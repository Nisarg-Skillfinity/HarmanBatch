#include "numpuzzle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NumPuzzle w;
    w.show();

    return a.exec();
}
