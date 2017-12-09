#include "mbexamen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MBexamen w;
    w.show();

    return a.exec();
}
