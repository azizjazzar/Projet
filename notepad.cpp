#include "notepad.h"
#include "ui_notepad.h"

notepad::notepad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notepad)
{
    ui->setupUi(this);
}

notepad::~notepad()
{
    delete ui;
}
