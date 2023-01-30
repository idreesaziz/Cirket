#include <QtWidgets/QApplication>

#include <QtNodes/ConnectionStyle>
#include <QtNodes/DataFlowGraphModel>
#include <QtNodes/DataFlowGraphicsScene>
#include <QtNodes/GraphicsView>
#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModelRegistry>

#include "models.hpp"

#include "CirketEditor.h"


using QtNodes::ConnectionStyle;
using QtNodes::DataFlowGraphicsScene;
using QtNodes::DataFlowGraphModel;
using QtNodes::GraphicsView;
using QtNodes::NodeDelegateModelRegistry;

static std::shared_ptr<NodeDelegateModelRegistry> registerDataModels()
{
    auto ret = std::make_shared<NodeDelegateModelRegistry>();

    ret->registerModel<NaiveDataModel>();

    /*
     We could have more models registered.
     All of them become items in the context meny of the scene.

     ret->registerModel<AnotherDataModel>();
     ret->registerModel<OneMoreDataModel>();

   */

    return ret;
}

static void setStyle()
{
    ConnectionStyle::setConnectionStyle(
        R"(
  {
    "ConnectionStyle": {
      "UseDataDefinedColors": true
    }
  }
  )");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CirketEditor w;
    w.show();

    //setStyle();

    //std::shared_ptr<NodeDelegateModelRegistry> registry = registerDataModels();
    //DataFlowGraphModel dataFlowGraphModel(registry);

    //DataFlowGraphicsScene scene(dataFlowGraphModel);

    //GraphicsView view(&scene);

    //view.setWindowTitle("Node-based flow editor");
    //view.resize(w.size().width(), w.size().height());
    //view.show();

    return a.exec();
}
