#pragma once
#include "Node.h"
class ExecPin : public Pin
{
public:
    ExecPin()
    {
        setDatatype("EXEC");
        setName("Begin");
    }
};

class BeginExecNode : public Node
{
    Q_OBJECT

public:

    BeginExecNode()
    {
        setCaption("Begin");
        setName("Begin");
        setOutputParams<ExecPin>();
    }
};

class EndExecNode : public Node
{
    Q_OBJECT

public:

    EndExecNode()
    {
        setCaption("End");
        setName("End");
        setInputParams<ExecPin>();
    }
};