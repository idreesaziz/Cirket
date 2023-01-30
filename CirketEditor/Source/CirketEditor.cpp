#include "CirketEditor.h"
#include "NodeEditor.h"

CirketEditor::CirketEditor(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    NodeEditor* editor = new NodeEditor(this);
    this->setCentralWidget(editor->getViewport().get());
}

CirketEditor::~CirketEditor()
{
}
