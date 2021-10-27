#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <iostream>
#include "client.h"
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
void MainWindow::on_ajouter_clicked()
{
Client c(ui->id->text(),ui->nom->text(),ui->prenom->text(),ui->adresse->text(),ui->radioButton->text(),"12");
c.ajouter();

}
