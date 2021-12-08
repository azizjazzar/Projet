#include "zied_dialog.h"
#include "ui_zied_dialog.h"
#include "zied_employe.h"
#include "zied_mainwindow.h"
#include "zied_account.h"
#include "zied_arduino.h"
#include <QMessageBox>
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
        m.set(e);
        m.show();
    }
    else if(e.account(ui->lineEdit->text(),ui->lineEdit_2->text()))
    {
        hide();
        a.set(e);
        a.show();
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Access denied!!!"),QObject::tr("Invalid login or/and password."),QMessageBox::Retry);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }
}


