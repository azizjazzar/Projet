#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "voyage.h"
#include <QString>
#include <QDate>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_chauf->setValidator ( new QIntValidator(10000000, 99999999, this));
    ui->tab_voyage->setModel(V.afficher_voyage());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ok_clicked()
{
    QString ref=ui->lineEdit_ref->text();
    int cin=ui->lineEdit_chauf->text().toInt();
    QString matricule=ui->lineEdit_matricule->text();
    QString etat=ui->comboBox_etat->currentText();
    QString depart=ui->comboBox_ligne->currentText();
    QString destination=ui->comboBox_dest->currentText();
    QString date=ui->dateEdit->text();
    QString heure_depart=ui->timeEdit_depart->text();
    QString heure_arrive=ui->timeEdit_arrive2->text();
    QString heure_arrive_prevu=ui->timeEdit_arrive1->text();

    Voyage V(ref,cin,matricule,etat,depart,destination,date , heure_depart,heure_arrive_prevu,heure_arrive);
    V.ajouter_voyage();
}

void MainWindow::on_pushButton_supprimer_clicked()
{

}


