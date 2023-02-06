#pragma once

#include <QtCore/QObject>

#include <QtNodes/NodeData>
#include <QtNodes/NodeDelegateModel>

#include <memory>
class Pin : public QtNodes::NodeData
{
private:
    QString dataType;
    QString name;

public:
    void setName(QString name)
    {
        this->name = name;
    }
    void setDatatype(QString dataType)
    {
        this->dataType = dataType;
    }
    QtNodes::NodeDataType type() const override { return QtNodes::NodeDataType{ dataType, name }; }
};

class Node : public QtNodes::NodeDelegateModel
{
    Q_OBJECT


private:
    QString mCaption;
    QString mName;
    std::vector<Pin> inParams;
    std::vector<Pin> outParams;

public:
    virtual ~Node() {}

protected:

    void setCaption(QString caption)
    {
        mCaption = caption;
    }

    void setName(QString name)
    {
        mName = name;
    }


    template <typename... dataTypes>
    void setInputParams()
    {
        inParams = { dataTypes()... };
    };

    template <typename... dataTypes>
    void setOutputParams()
    {
        outParams = { dataTypes()... };
    };

public:
    QString caption() const override { return QString(mCaption); }

    QString name() const override { return QString(mName); }

public:
    unsigned int nPorts(QtNodes::PortType const portType) const override
    {
        switch (portType) {
        case QtNodes::PortType::In:
            return inParams.size();
            break;
        case QtNodes::PortType::Out:
            return outParams.size();
            break;
        }
    }

    QtNodes::NodeDataType dataType(QtNodes::PortType const portType, QtNodes::PortIndex const portIndex) const override
    {
        switch (portType) {

        case QtNodes::PortType::In:
            return inParams[portIndex].type();
            break;

        case QtNodes::PortType::Out:
            return outParams[portIndex].type();
            break;

        case QtNodes::PortType::None:
            break;
        }
        // FIXME: control may reach end of non-void function [-Wreturn-type]
        return QtNodes::NodeDataType();
    }

    std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex const port) override
    {

        return std::make_shared<Pin>();
    }

    void setInData(std::shared_ptr<QtNodes::NodeData>, QtNodes::PortIndex const) override
    {
        //
    }

    QWidget* embeddedWidget() override { return nullptr; }
};