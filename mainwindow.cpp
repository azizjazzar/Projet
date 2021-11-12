#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    employe e;
    ui->tableView->setModel(e.affichier());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajout_clicked()
{
   QString nom=ui->ajout_nom->text();
   QString prenom=ui->ajout_prenom->text();
   QDate date=ui->ajout_date->date();
   QString CIN=ui->ajout_cin->text();
   int num=ui->ajout_num->text().toInt();
   QString Email=ui->ajout_email->text();
   QString role=ui->ajout_role->currentText();
   QString login=ui->ajout_login->text();
   QString password=ui->ajout_password->text();
   employe e(nom,prenom,date,CIN,num,Email,role,login,password);
   bool test=e.ajouter();
   /*if(test)
       QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr(("ajout effectué.")));
   else
       QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr(("ajout non effectué.")));*/
   ui->tableView->setModel(e.affichier());
   ui->ajout_cin->setText("");
   ui->ajout_prenom->setText("");
   ui->ajout_nom->setText("");
   ui->ajout_num->setText("");
   ui->ajout_email->setText("");
   ui->ajout_login->setText("");
   ui->ajout_password->setText("");
}

void MainWindow::on_pushButton_supp_clicked()
{
    employe e;
    e.supprimer(ui->cin_mod->text());
    ui->tableView->setModel(e.affichier());
    ui->cin_mod->setText("");
}

void MainWindow::on_pushButton_mod_clicked()
{
    employe e;
    e.modifier(ui->attribut_mod->currentText().toStdString(),ui->mod_val->text(),ui->cin_mod->text());
    ui->tableView->setModel(e.affichier());
    ui->cin_mod->setText("");
    ui->mod_val->setText("");
}

void MainWindow::on_pushButton_aff_clicked()
{
    employe e;
    ui->tableView->setModel(e.affichier());
}
