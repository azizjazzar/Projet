#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <iostream>
#include "client.h"
#include <QMessageBox>
#include <QString>
#include "carte.h"
#include <cstdio>
#include <QFile>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPointF>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Client c;

    ui->setupUi(this);
    ui->pointcarte->setValidator(new QIntValidator(0,9999999,this));
    ui->comboBox_2->setModel(c.autoremplisage());
    ui->calendarWidget->hide();
    ui->fonctionaliteframe->hide();
    ui->Client_frame->hide();
    QDate datecurent=QDate::currentDate();
    QDate datelundi;
    QDate datemardi;
    QDate datemercredi;
    QDate datejeudi;
    QDate datevendredi;
    int d=datecurent.toString("dd").toInt();
    int m=datecurent.toString("MM").toInt();
    int y=datecurent.toString("yyyy").toInt();
    QString datenom = QDate::currentDate().toString("dddd");
    QBarSet *set0 = new QBarSet("Homme");
       QBarSet *set1 = new QBarSet("Femme");
    //stat
    if (datenom=="lundi")
    {

        datelundi.setDate(y,m,d);
        datemardi.setDate(y,m,d+1);
        datemercredi.setDate(y,m,d+2);
        datejeudi.setDate(y,m,d+3);
        datevendredi.setDate(y,m,d+4);
        *set0 <<c.homme(datelundi)<<c.homme(datemardi)<<c.homme(datemercredi)<<c.homme(datejeudi)<<c.homme(datevendredi);


         *set1 <<c.femme(datelundi)<<c.femme(datemardi)<<c.femme(datemercredi)<<c.femme(datejeudi)<<c.femme(datevendredi);
    }
    else if (datenom=="mardi")
    {
        datelundi.setDate(y,m,d-1);
        datemardi.setDate(y,m,d);
        datemercredi.setDate(y,m,d+1);
        datejeudi.setDate(y,m,d+2);
        datevendredi.setDate(y,m,d+3);
        *set0 <<c.homme(datelundi)<<c.homme(datemardi)<<c.homme(datemercredi)<<c.homme(datejeudi)<<c.homme(datevendredi);
          *set1 <<c.femme(datelundi)<<c.femme(datemardi)<<c.femme(datemercredi)<<c.femme(datejeudi)<<c.femme(datevendredi);
    }
    else if (datenom=="mercredi")
    {
        datelundi.setDate(y,m,d-2);
        datemardi.setDate(y,m,d-1);
        datemercredi.setDate(y,m,d);
        datejeudi.setDate(y,m,d+1);
        datevendredi.setDate(y,m,d+2);
        *set0 <<c.homme(datelundi)<<c.homme(datemardi)<<c.homme(datemercredi)<<c.homme(datejeudi)<<c.homme(datevendredi);
          *set1 <<c.femme(datelundi)<<c.femme(datemardi)<<c.femme(datemercredi)<<c.femme(datejeudi)<<c.femme(datevendredi);
    }
    else if (datenom=="jeudi")
    {
        datelundi.setDate(y,m,d-3);
        datemardi.setDate(y,m,d-2);
        datemercredi.setDate(y,m,d-1);
        datejeudi.setDate(y,m,d);
        datevendredi.setDate(y,m,d+1);
        *set0 <<c.homme(datelundi)<<c.homme(datemardi)<<c.homme(datemercredi)<<c.homme(datejeudi)<<c.homme(datevendredi);
          *set1 <<c.femme(datelundi)<<c.femme(datemardi)<<c.femme(datemercredi)<<c.femme(datejeudi)<<c.femme(datevendredi);
    }

    else if (datenom=="samedi")
    {
        datelundi.setDate(y,m,d-1);
        datemardi.setDate(y,m,d-2);
        datemercredi.setDate(y,m,d-3);
        datejeudi.setDate(y,m,d-4);
        datevendredi.setDate(y,m,d);
        *set0 <<c.homme(datelundi)<<c.homme(datemardi)<<c.homme(datemercredi)<<c.homme(datejeudi)<<c.homme(datevendredi);
          *set1 <<c.femme(datelundi)<<c.femme(datemardi)<<c.femme(datemercredi)<<c.femme(datejeudi)<<c.femme(datevendredi);
    }






       QBarSeries *seriess = new QBarSeries();
        seriess->append(set0);
        seriess->append(set1);

        QChart *chartt = new QChart();
           chartt->addSeries(seriess);
           chartt->setAnimationOptions(QChart::SeriesAnimations);

           QStringList categories;
              categories << "Lundi" << "Mardi" << "Mercredi" << "Jeudi" <<"Vendredi"<<"Samedi";
              QBarCategoryAxis *axisX = new QBarCategoryAxis();
              axisX->append(categories);
              chartt->addAxis(axisX, Qt::AlignBottom);
              seriess->attachAxis(axisX);

              QValueAxis *axisY = new QValueAxis();

                  axisY->setRange(0, 20);
              chartt->addAxis(axisY, Qt::AlignLeft);
              seriess->attachAxis(axisY);
              chartt->legend()->setVisible(true);
                 chartt->legend()->setAlignment(Qt::AlignBottom);
                 QChartView *chartView = new QChartView(chartt);
                 chartView->chart()->setTheme(QChart::ChartThemeDark);
                   chartView->resize(500,400);
                 chartt->setBackgroundBrush(QBrush(QColor(47, 43, 63)));
                     chartView->setRenderHint(QPainter::Antialiasing);
                  chartView->setParent(ui->horizontalFrame_2);

     //pie

    QPieSeries *series = new QPieSeries();

       series->append("Enfant:", c.calculenfant());
       series->append("Adulte:", c.calculadulte());
       series->append("Personne âgée :", c.calculpersonneage());
       series->setLabelsVisible();


        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->legend()->hide();
           for(auto slice : series->slices())
           slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));



       QChartView *chartview = new QChartView(chart);
        chartview->chart()->setTheme(QChart::ChartThemeDark);
        chart->setBackgroundBrush(QBrush(QColor(47, 43, 63)));

       chartview->setParent(ui->horizontalFrame);
       chartview->resize(430,400);



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
    ui->widget->hide();


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
            ui->widget->show();

}


void MainWindow::on_gestionclient_clicked()
{
     ui->fonctionaliteframe->hide();
    ui->Client_frame->show();
     ui->widget->hide();
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
    Client c;
     ui->Client_frame->hide();
     ui->fonctionaliteframe->show();
     ui->comboBox_2->setModel(c.autoremplisage());
}
//crud

void MainWindow::on_ajouter_clicked()
{
    QRegExp rx;
    rx.setPattern("\\d+");
    QString genre;
    QMessageBox msgBox;
    if (ui->nom->text().contains(rx) || ui->prenom->text().contains(rx) )
    {
    msgBox.setText("Nom prenom doit etre chaine!!");
    }
    else
    {
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
    if (c.recherchee()!="")
    if (c.supprimer() )
    {
         msgBox.setText("Suppression avec succees");
         ui->tableView->setModel(c.afficher());
    }
    else
        msgBox.setText("Probleme de suppresion");
    else
    msgBox.setText("id inexsistant");
     msgBox.exec();
}

void MainWindow::on_modifier_clicked()
{
    QString genre;
    QMessageBox msgBox;
    QRegExp rx;
    rx.setPattern("\\d+");
    if (ui->nom->text().contains(rx) || ui->prenom->text().contains(rx) )
    {
    msgBox.setText("nom prenom doit etre chainee");
    }
    else
    {
        if (ui->radioButton->isChecked())
            genre=ui->radioButton->text();
        else
            genre=ui->radioButton_2->text();

            QString date=ui->dateedit->text();
            Client c(ui->id->text(),ui->nom->text(),ui->prenom->text(),ui->adresse->text(),genre,date);
            if (c.update() && c.recherchee()!="")
            {
            msgBox.setText("Mise a jour avec succes");
            ui->tableView->setModel(c.afficher());
            }
            else
            {
               msgBox.setText("Probleme de mise a jour");
            }
            ui->tableView->setModel(c.afficher());
    }
    msgBox.exec();
}

void MainWindow::on_pushButton_clicked()
{

    QMessageBox msgBox;

carte c(ui->comboBox_2->currentText(),ui->pointcarte->text());
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
    carte c(ui->comboBox_2->currentText(),ui->pointcarte->text());
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
    carte c(ui->comboBox_2->currentText(),ui->pointcarte->text());
    if (c.update() & (c.recherchee()!=""))
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

void MainWindow::on_recherche_2_clicked()
{

  Client c;
   ui->tableView->setModel(c.trie(ui->comboBox->currentText()));
}

void MainWindow::on_recherche_clicked()
{
    Client c;
    c.setid(ui->id->text());
     ui->tableView->setModel(c.recherche());

}

void MainWindow::on_pushButton_5_clicked()
{
    Client c;
    QMessageBox msgBox;
     QString date=ui->datesupp->text();
   c.setdate_enrg(date);




           QFile file("C:/Users/aziz/Documents/qtcreotorcss/Client.txt");
               if (file.open(QFile::Text | QFile::WriteOnly))
               {
                   QSqlQuery q=c.chercher();
                    QString str;
                     QByteArray br;
                   while (q.next())
                   {
                       for (int i=0;i<6;i++)
                       {
                           if (i!=5)
                           {
                               str=q.value(i).toString();
                               br=str.toUtf8();
                           }
                           else
                           {
                               str=q.value(i).toString();
                               str.resize(10);
                               br=str.toUtf8();
                           }
                        file.write(br+" ");
                       }
                        file.write("\n");
                   }
                   file.close();
                   if (c.supprimer_innactif())
                   msgBox.setText("1-Clients innactif supprimer\n2-Enregistrement fichier efféctuer");
                   else
                   msgBox.setText("Probléme au niveau de requette");
               }
               else
               msgBox.setText("Probléme au niveau de fichier");

   msgBox.exec();

}
