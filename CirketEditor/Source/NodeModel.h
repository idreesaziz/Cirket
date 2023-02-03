#pragma once
#include "Pin.h"
#include <QtCore/QObject>

#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModel>

#include <memory>
//------------------------------------------------------------------------------

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class NodeModel : public QtNodes::NodeDelegateModel
{
    Q_OBJECT
private:
    std::shared_ptr<std::vector<Pin>> inputs;
    std::shared_ptr <std::vector<Pin>> outputs;


public:
    NodeModel(std::shared_ptr<std::vector<Pin>> inputs, std::shared_ptr<std::vector<Pin>> outputs) 
        : NodeDelegateModel(),
          inputs(inputs),
          outputs(outputs)
    {}
    virtual ~NodeModel() {}

public:
    QString caption() const override { return QString("Naive Data Model"); }

    QString name() const override { return QString("NaiveDataModel"); }

public:
    unsigned int nPorts(QtNodes::PortType const portType) const override
    {
        unsigned int result = 1;

        switch (portType) {
        case QtNodes::PortType::In:
            return (*inputs).size();
            break;

        case QtNodes::PortType::Out:
            return (*outputs).size();
            break;
        case QtNodes::PortType::None:
            break;
        }

        return result;
    }

    QtNodes::NodeDataType dataType(QtNodes::PortType const portType, QtNodes::PortIndex const portIndex) const override
    {
        switch (portType) {
        case QtNodes::PortType::In:
            return (*inputs)[portIndex].GetPinData().type();
            break;

        case QtNodes::PortType::Out:
            return (*outputs)[portIndex].GetPinData().type();
            break;

        case QtNodes::PortType::None:
            break;
        }
        // FIXME: control may reach end of non-void function [-Wreturn-type]
        return QtNodes::NodeDataType();
    }

    std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex const port) override
    {
    }

    void setInData(std::shared_ptr<QtNodes::NodeData>, QtNodes::PortIndex const) override
    {
        //
    }

    QWidget* embeddedWidget() override { return nullptr; }
};
