#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <iostream>
#include "client.h"
#include <QMessageBox>
#include <QString>
#include "carte.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->calendarWidget->hide();
   ui->fonctionaliteframe->hide();
      ui->Client_frame->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//gestion ui

void MainWindow::on_calendrier_clicked()
{
    if(ui->calendarWidget->isHidden())
        ui->calendarWidget->show();
    else
        ui->calendarWidget->hide();

}



void MainWindow::on_accueil_clicked()
{
        ui->fonctionaliteframe->hide();
           ui->Client_frame->hide();

}

void MainWindow::on_statistique_clicked()
{
        ui->fonctionaliteframe->hide();
           ui->Client_frame->hide();

}


void MainWindow::on_gestionclient_clicked()
{
     ui->fonctionaliteframe->hide();
    ui->Client_frame->show();
}

void MainWindow::on_reset_clicked()
{
   QDate dates(2000,1,1);
ui->nom->setText("");
ui->prenom->setText("");
ui->adresse->setText("");
ui->id->setText("");
ui->radioButton->setChecked(1);
ui->dateedit->setDate(dates);
}


void MainWindow::on_Fonctionalite_clicked()
{
     ui->Client_frame->hide();
     ui->fonctionaliteframe->show();
}
//crud

void MainWindow::on_ajouter_clicked()
{
    QString genre;
    QMessageBox msgBox;
    if (ui->radioButton->isChecked())
        genre=ui->radioButton->text();
    else
        genre=ui->radioButton_2->text();

QString date=ui->dateedit->text();
Client c(ui->id->text(),ui->nom->text(),ui->prenom->text(),ui->adresse->text(),genre,date);
    if (c.ajouter())
    {
    msgBox.setText("Ajout avec succes");
    ui->tableView->setModel(c.afficher());
    }
    else
    {
       msgBox.setText("Probleme d'ajout");
    }
    msgBox.exec();

}



void MainWindow::on_afficher_clicked()
{
    Client c;
    ui->tableView->setModel(c.afficher());
}

void MainWindow::on_supprimer_clicked()
{
    Client c;
     QMessageBox msgBox;
    c.setid(ui->id->text());
    if (c.supprimer())
    {
         msgBox.setText("Suppression avec succees");
         ui->tableView->setModel(c.afficher());
    }
    else
        msgBox.setText("Probleme de suppresion");
    msgBox.exec();
}

void MainWindow::on_modifier_clicked()
{
    QString genre;
    QMessageBox msgBox;
    if (ui->radioButton->isChecked())
        genre=ui->radioButton->text();
    else
        genre=ui->radioButton_2->text();
QString date=ui->dateedit->text();
Client c(ui->id->text(),ui->nom->text(),ui->prenom->text(),ui->adresse->text(),genre,date);
if (c.update())
{
msgBox.setText("Mise a jour avec succes");
ui->tableView->setModel(c.afficher());
}
else
{
   msgBox.setText("Probleme de mise a jour");
}
msgBox.exec();
ui->tableView->setModel(c.afficher());

}

void MainWindow::on_pushButton_clicked()
{

    QMessageBox msgBox;

carte c(ui->idcarte->text(),ui->pointcarte->text());
    if (c.ajouter())
    {
    msgBox.setText("Ajout avec succes");
    ui->tableView_2->setModel(c.afficher());
    }
    else
    {
       msgBox.setText("Probleme d'ajout");
    }
    msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    carte c;
    ui->tableView_2->setModel(c.afficher());
}

void MainWindow::on_pushButton_3_clicked()
{
    carte c(ui->idcarte->text(),ui->pointcarte->text());
     QMessageBox msgBox;
    if (c.supprimer())
    {
         msgBox.setText("Suppression avec succees");
         ui->tableView_2->setModel(c.afficher());
    }
    else
        msgBox.setText("Probleme de suppresion");
    msgBox.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox msgBox;
    carte c(ui->idcarte->text(),ui->pointcarte->text());
    if (c.update())
    {
    msgBox.setText("Mise a jour avec succes");
    ui->tableView_2->setModel(c.afficher());
    }
    else
    {
       msgBox.setText("Probleme de mise a jour");
    }
    msgBox.exec();
}
