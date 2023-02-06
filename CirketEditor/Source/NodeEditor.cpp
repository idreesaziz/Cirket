#include "NodeEditor.h"

#include <QtNodes/ConnectionStyle>
#include <QtNodes/DataFlowGraphModel>
#include <QtNodes/DataFlowGraphicsScene>
#include <QtNodes/GraphicsView>
#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModelRegistry>
#include "models.hpp"
#include "Hadamard.h"
#include "Execution.h"
#include "QubitNode.h"

static std::shared_ptr<QtNodes::NodeDelegateModelRegistry> registerDataModels()
{
    auto ret = std::make_shared<QtNodes::NodeDelegateModelRegistry>();

    ret->registerModel<BeginExecNode>();
    ret->registerModel<HadamardNode>();
    ret->registerModel<QubitNode>();
    ret->registerModel<EndExecNode>();

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
