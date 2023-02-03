#include "NodeEditor.h"

#include <QtNodes/ConnectionStyle>
#include <QtNodes/DataFlowGraphModel>
#include <QtNodes/DataFlowGraphicsScene>
#include <QtNodes/GraphicsView>
#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModelRegistry>
#include "models.hpp"
#include "Hadamard.h"

static std::shared_ptr<QtNodes::NodeDelegateModelRegistry> registerDataModels()
{
    auto ret = std::make_shared<QtNodes::NodeDelegateModelRegistry>();

    ret->registerModel<Hadamard>();

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
    QtNodes::ConnectionStyle::setConnectionStyle(
        R"(
  {
    "ConnectionStyle": {
      "UseDataDefinedColors": true
    }
  }
  )");
}

std::shared_ptr<QtNodes::GraphicsView> NodeEditor::getViewport()
{
	return mGraphicsView;
}

NodeEditor::NodeEditor(QWidget* parent)
{
    setStyle();

    mRegistry = registerDataModels();
    mGraphModel = std::make_shared<QtNodes::DataFlowGraphModel>(mRegistry);

    mGraphicsScene = std::make_shared<QtNodes::DataFlowGraphicsScene>(*mGraphModel);

    mGraphicsView = std::make_shared<QtNodes::GraphicsView>(mGraphicsScene.get(), parent);
    mGraphicsView->resize(800, 500);
    mGraphicsView->show();
}
