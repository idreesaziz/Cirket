#pragma once
#include "Node.h"
class QubitPin : public Pin
{
public:
    QubitPin()
    {
        setDatatype("QUBIT");
        setName("Qubit");
    }
};

class QubitNode : public Node
{
    Q_OBJECT

public:

    QubitNode()
    {
        setCaption("Qubit");
        setName("Qubit");
        setOutputParams<QubitPin>();
    }
};