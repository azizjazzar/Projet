#include "dialog.h"
#include "ui_dialog.h"
#include "employe.h"
#include "mainwindow.h"
#include "account.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    employe e;
    if(e.access(ui->lineEdit->text(),ui->lineEdit_2->text()))
    {
        hide();
        a.set(e);
        a.show();
        w.show();
    }
    else if(e.account(ui->lineEdit->text(),ui->lineEdit_2->text()))
    {
        hide();
        a.set(e);
        a.show();
    }
}


