#include "account.h"
#include "ui_account.h"
#include "employe.h"
account::account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::account)
{
    ui->setupUi(this);
    ui->ajout_cin->setReadOnly(true);
    ui->ajout_nom->setReadOnly(true);
    ui->ajout_prenom->setReadOnly(true);
    ui->ajout_num->setReadOnly(true);
    ui->ajout_date->setReadOnly(true);
    ui->ajout_role->setReadOnly(true);
    ui->ajout_email->setReadOnly(true);
    ui->ajout_login->setReadOnly(true);
    ui->ajout_password->setReadOnly(true);
}

account::~account()
{
    delete ui;
}

void account::set(employe a)
{
    e=a;
    ui->ajout_cin->setText(e.get_cin());
    ui->ajout_nom->setText(e.get_nom());
    ui->ajout_prenom->setText(e.get_prenom());
    QString S=QString::fromStdString(to_string(e.get_num()));
    ui->ajout_num->setText(S);
    ui->ajout_date->setDate(e.get_date());
    ui->ajout_role->setText(e.get_role());
    ui->ajout_email->setText(e.get_email());
    ui->ajout_login->setText(e.get_login());
    ui->ajout_password->setText(e.get_password());
    ui->tableView->setModel(e.emploi());
}






