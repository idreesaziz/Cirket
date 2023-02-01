#include "CirketEditor.h"
#include "NodeEditor.h"
#include <QDir>

CirketEditor::CirketEditor(QWidget *parent)
    : QMainWindow(parent)
{
    SetupUI();
    NodeEditor* editor = new NodeEditor(this);
    this->setCentralWidget(editor->getViewport().get());
}

void CirketEditor::SetupUI()
{
    auto x = QDir::current();
    auto y = ":" + x.path() + "/UI/darkstyle.qss";
    QFile f(x.path() + "/UI/darkstyle.qss");
    if (!f.exists()) {
        printf("Unable to set stylesheet, file not found\n");
    }
    else {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

    ui.setupUi(this);
}

CirketEditor::~CirketEditor()
{
}
