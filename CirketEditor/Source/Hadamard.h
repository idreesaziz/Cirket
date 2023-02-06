#pragma once
#include "Node.h"
#include "QuBitNode.h"
#include "Execution.h"

class HadamardNode : public Node
{
    Q_OBJECT

public:

    HadamardNode()
    {
        setCaption("Hadamard");
        setName("Hadamard Gate");
        setInputParams<ExecPin, QubitPin>();
        setOutputParams<ExecPin, QubitPin>();
    }
};