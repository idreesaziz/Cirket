#pragma once
#pragma once

#include <QtCore/QObject>

#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModel>

#include <memory>

/// The class can potentially incapsulate any user data which
/// needs to be transferred within the Node Editor graph
class ExecPin : public QtNodes::NodeData
{
public:
    QtNodes::NodeDataType type() const override { return QtNodes::NodeDataType{ "EXEC_PIN", "Exec" }; }
};


//------------------------------------------------------------------------------

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class BeginExecutionNode : public QtNodes::NodeDelegateModel
{
    Q_OBJECT

public:
    virtual ~BeginExecutionNode() {}

public:
    QString caption() const override { return QString("Begin"); }

    QString name() const override { return QString("Begin"); }

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
                return ExecPin().type();
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
        return std::make_shared<ExecPin>();
    }

    void setInData(std::shared_ptr<QtNodes::NodeData>, QtNodes::PortIndex const) override
    {
        //
    }

    QWidget* embeddedWidget() override { return nullptr; }
};

class EndExecutionNode : public QtNodes::NodeDelegateModel
{
    Q_OBJECT

public:
    virtual ~EndExecutionNode() {}

public:
    QString caption() const override { return QString("End"); }

    QString name() const override { return QString("End"); }

public:
    unsigned int nPorts(QtNodes::PortType const portType) const override
    {
        switch (portType) {
        case QtNodes::PortType::In:
            return 1;
            break;
        case QtNodes::PortType::Out:
            return 0;
            break;
        }
    }

    QtNodes::NodeDataType dataType(QtNodes::PortType const portType, QtNodes::PortIndex const portIndex) const override
    {
        switch (portType) {

        case QtNodes::PortType::In:
            switch (portIndex) {
            case 0:
                return ExecPin().type();
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
        return std::make_shared<ExecPin>();
    }

    void setInData(std::shared_ptr<QtNodes::NodeData>, QtNodes::PortIndex const) override
    {
        //
    }

    QWidget* embeddedWidget() override { return nullptr; }
};
