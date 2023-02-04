#pragma once
#pragma once
#pragma once

#include <QtCore/QObject>

#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModel>

#include <memory>


class QubitPin : public QtNodes::NodeData
{
public:
    QtNodes::NodeDataType type() const override { return QtNodes::NodeDataType{ "QUBIT_PIN", "Qubit" }; }
};



//------------------------------------------------------------------------------

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class QubitNode : public QtNodes::NodeDelegateModel
{
    Q_OBJECT

public:
    virtual ~QubitNode() {}

public:
    QString caption() const override { return QString("Qubit"); }

    QString name() const override { return QString("Qubit"); }

public:
    unsigned int nPorts(QtNodes::PortType const portType) const override
    {
        switch (portType) {
        case QtNodes::PortType::In:
            return 0;
            break;
        case QtNodes::PortType::Out:
            return 1;
            break;
        }
    }

    QtNodes::NodeDataType dataType(QtNodes::PortType const portType, QtNodes::PortIndex const portIndex) const override
    {
        switch (portType) {

        case QtNodes::PortType::Out:
            switch (portIndex) {
            case 0:
                return QubitPin().type();
            }
            break;

        case QtNodes::PortType::None:
            break;
        }
        // FIXME: control may reach end of non-void function [-Wreturn-type]
        return QtNodes::NodeDataType();
    }

    std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex const port) override
    {
        return std::make_shared<QubitPin>();
    }

    void setInData(std::shared_ptr<QtNodes::NodeData>, QtNodes::PortIndex const) override
    {
        //
    }

    QWidget* embeddedWidget() override { return nullptr; }
};