#include <QtWidgets/QApplication>

#include <QtNodes/ConnectionStyle>
#include <QtNodes/DataFlowGraphModel>
#include <QtNodes/DataFlowGraphicsScene>
#include <QtNodes/GraphicsView>
#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModelRegistry>

#include "models.hpp"

#include "CirketEditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CirketEditor w;
    w.show();

    return a.exec();
}
