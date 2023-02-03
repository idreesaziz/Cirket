#pragma once

#include <QtCore/QObject>

#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModel>

#include <memory>

/// The class can potentially incapsulate any user data which
/// needs to be transferred within the Node Editor graph
class QubitPin : public QtNodes::NodeData
{
public:
    QtNodes::NodeDataType type() const override { return QtNodes::NodeDataType{ "QUBIT_PIN", "Qubit" }; }
};


//------------------------------------------------------------------------------

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class Hadamard : public QtNodes::NodeDelegateModel
{
    Q_OBJECT

public:
    virtual ~Hadamard() {}

public:
    QString caption() const override { return QString("Hadamard"); }

    QString name() const override { return QString("Hadamard Gate"); }

public:
    unsigned int nPorts(QtNodes::PortType const portType) const override
    {
        return 1;
    }

    QtNodes::NodeDataType dataType(QtNodes::PortType const portType, QtNodes::PortIndex const portIndex) const override
    {
        switch (portType) {
        case QtNodes::PortType::In:
            switch (portIndex) {
            case 0:
                return QubitPin().type();
            }
            break;

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
