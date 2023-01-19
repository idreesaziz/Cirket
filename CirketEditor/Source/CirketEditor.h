#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CirketEditor.h"

class CirketEditor : public QMainWindow
{
    Q_OBJECT

public:
    CirketEditor(QWidget *parent = nullptr);
    ~CirketEditor();

private:
    Ui::CirketEditorClass ui;
};
