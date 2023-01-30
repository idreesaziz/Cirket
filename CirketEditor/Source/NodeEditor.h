#pragma once
#include <QtNodes/GraphicsView>
#include <QtNodes/ConnectionStyle>
#include <QtNodes/DataFlowGraphModel>
#include <QtNodes/DataFlowGraphicsScene>
#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModelRegistry>
#include <memory>

class NodeEditor
{

private:
	std::shared_ptr<QtNodes::NodeDelegateModelRegistry> mRegistry;
	std::shared_ptr<QtNodes::DataFlowGraphModel> mGraphModel;
	std::shared_ptr<QtNodes::DataFlowGraphicsScene> mGraphicsScene;
	std::shared_ptr<QtNodes::GraphicsView> mGraphicsView;

public:
	std::shared_ptr<QtNodes::GraphicsView> getViewport();
	NodeEditor(QWidget* parent);

};

