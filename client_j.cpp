#include "client_j.h"
#include "ui_client_j.h"
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
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include "arduino.h"


client_j::client_j(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::client_j)
{
    Client c;

    ui->setupUi(this);
    ui->pointcarte->setValidator(new QIntValidator(0,9999999,this));
    ui->comboBox_2->setModel(c.autoremplisage());
    ui->calendarWidget->hide();
    ui->fonctionaliteframe->hide();
    ui->Client_frame->hide();
    ui->rfid->hide();
    ui->tableView->setModel(c.afficher());
    /*
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

    else if (datenom=="vendredi")
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
              categories << "Lundi" << "Mardi" << "Mercredi" << "Jeudi" <<"Vendredi";
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
        chart->setAnimationOptions(QChart::AllAnimations);

       chartview->setParent(ui->horizontalFrame);
       chartview->resize(430,400);
       */



}

client_j::~client_j()
{
    delete ui;
}

//gestion ui

void client_j::on_calendrier_clicked()
{
    if(ui->calendarWidget->isHidden())
        ui->calendarWidget->show();
    else
        ui->calendarWidget->hide();
    ui->widget->hide();


}



void client_j::on_accueil_clicked()
{
        ui->fonctionaliteframe->hide();
           ui->Client_frame->hide();
        ui->widget->show();
           ui->rfid->hide();

}

void client_j::on_statistique_clicked()
{
        ui->fonctionaliteframe->hide();
           ui->Client_frame->hide();
            ui->widget->show();
               ui->rfid->hide();

}


void client_j::on_gestionclient_clicked()
{
     ui->fonctionaliteframe->hide();
    ui->Client_frame->show();
     ui->widget->hide();
        ui->rfid->hide();
}

void client_j::on_reset_clicked()
{
   QDate dates(2000,1,1);
ui->nom->setText("");
ui->prenom->setText("");
ui->adresse->setText("");
ui->id->setText("");
ui->radioButton->setChecked(1);
ui->dateedit->setDate(dates);
}


void client_j::on_Fonctionalite_clicked()
{
    Client c;
     ui->Client_frame->hide();
     ui->fonctionaliteframe->show();
     ui->comboBox_2->setModel(c.autoremplisage());
      ui->widget->hide();
         ui->rfid->hide();
}
//crud

void client_j::on_ajouter_clicked()
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



void client_j::on_afficher_clicked()
{
    Client c;
    ui->tableView->setModel(c.afficher());
}

void client_j::on_supprimer_clicked()
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

void client_j::on_modifier_clicked()
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

void client_j::on_pushButton_clicked()
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

void client_j::on_pushButton_2_clicked()
{
    carte c;
    ui->tableView_2->setModel(c.afficher());
}

void client_j::on_pushButton_3_clicked()
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

void client_j::on_pushButton_4_clicked()
{
    QMessageBox msgBox;
    carte c(ui->comboBox_2->currentText(),ui->pointcarte->text());
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

void client_j::on_recherche_2_clicked()
{

  Client c;
   ui->tableView->setModel(c.trie(ui->comboBox->currentText()));
}

void client_j::on_recherche_clicked()
{
    Client c;
    c.setid(ui->id->text());
     ui->tableView->setModel(c.recherche());

}

void client_j::on_pushButton_5_clicked()
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
void client_j::on_pushButton_7_clicked()
{
    QString strStream;
                              QTextStream out(&strStream); //eureur

                                const int rowCount = ui->tableView->model()->rowCount();
                                const int columnCount = ui->tableView->model()->columnCount();

                                out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("strTitle")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"

                                   //     "<align='right'> " << datefich << "</align>"
                                    "<center> <H1>Liste des clients </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                // headers
                                out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tableView->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";

                                // data table
                                for (int row = 0; row < rowCount; row++) {
                                    out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                    for (int column = 0 ; column < columnCount; column++) {
                                        if (!ui->tableView->isColumnHidden(column)) {
                                            QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                        }
                                    }
                                    out << "</tr>\n";
                                }
                                out <<  "</table> </center>\n"
                                    "</body>\n"
                                    "</html>\n";

                          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                           QPrinter printer (QPrinter::PrinterResolution);
                            printer.setOutputFormat(QPrinter::PdfFormat);
                           printer.setPaperSize(QPrinter::A4);
                          printer.setOutputFileName(fileName);

                           QTextDocument  doc;
                            doc.setHtml(strStream);
                            doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                            doc.print(&printer);

}

void client_j::on_pushButton_8_clicked()
{
    Arduino a;
    switch(a.connect_arduino())
    {
        case (0):
            qDebug()<<"arduino is available and connected to"<<a.getarduino_port_name();
        break;
        case (1):
            qDebug()<<"arduino is available but not connected to"<<a.getarduino_port_name();
        break;
        case (-1):
            qDebug()<<"arduino is not available";
        break;

    }
    qDebug()<<"en attente de carte..." ;
    QString id=a.read_from_arduino();
    qDebug()<<id ;
    a.close_arduino();

    Client c;
    c.setid(id);
    ui->tableView_3->setModel(c.recherche());
     c.carte_mag();



}

void client_j::on_statistique_2_clicked()
{
    ui->fonctionaliteframe->hide();
       ui->Client_frame->hide();
        ui->widget->hide();
        ui->rfid->show();
}
