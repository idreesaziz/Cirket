#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CirketEditor.h"

class CirketEditor : public QMainWindow
{
    Q_OBJECT

public:
    CirketEditor(QWidget *parent = nullptr);
    void SetupUI();
    ~CirketEditor();

private:
    Ui::CirketEditorClass ui;
};
