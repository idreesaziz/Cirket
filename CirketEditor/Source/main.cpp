#include "CirketEditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CirketEditor w;
    w.show();
    return a.exec();
}
