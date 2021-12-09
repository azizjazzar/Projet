#include "Selim_mainwindow.h"
#include "ui_Selim_mainwindow.h"
#include "Selim_abonnement.h"
#include "Selim_notification.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QFile>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QPainter>
#include <QPdfWriter>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QtPrintSupport>


Selim_MainWindow::Selim_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Selim_MainWindow)
{ abonnement A;
    ui->setupUi(this);
    ui->tableView_ab->setModel(A.afficher_abonnement());
    ui->spinBox_duree2->setRange(0,28);
    ui->spinBox_duree2_modif->setRange(0,28);

}

Selim_MainWindow::~Selim_MainWindow()
{
    delete ui;
}


void Selim_MainWindow::on_ajouter_clicked()
{
   QString ID=ui->lineEdit_ID->text();
   QString Duree1=ui->spinBox_duree1->text();
   QString Duree2=ui->spinBox_duree2->text();
   int Prix=ui->lineEdit_prix->text().toInt();
   abonnement A;
   bool test = A.ajouter_abonnement(ID,Duree1+"/"+Duree2,Prix);
   if(test )
       {
       QMessageBox::information(nullptr, QObject::tr("Ajout terminé"),
                         QObject::tr("abonnement ajouté.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_ab->setModel(A.afficher_abonnement());
       }

         else
         {
             QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonement"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
}

void Selim_MainWindow::on_supprimer_clicked()
{
    abonnement supp;
    if(supp.supprimer_abonnement(ui))
                  {
                      QMessageBox ::information(this,"","supprimé!")  ;


                         ui->tableView_ab->setModel(supp.afficher_abonnement());

                  }
                  else{
                      QMessageBox ::critical(this,"","erreur!")  ;
    }
}

void Selim_MainWindow::on_pushButton_modifier_clicked()
{
    QString ID=ui->lineEdit_id_select->text();
    QString Duree1=ui->spinBox_duree1_modif->text();
    QString Duree2=ui->spinBox_duree2_modif->text();
    int Prix=ui->lineEdit_prix_modif->text().toInt();
    abonnement A;
    bool test = A.modifier_abonnement(ID,Duree1+"/"+Duree2,Prix);
    if(test )
        {
        QMessageBox::information(nullptr, QObject::tr("modification terminé"),
                          QObject::tr("abonnement modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableView_ab->setModel(A.afficher_abonnement());
        }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("modifier un abonement"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
}

void Selim_MainWindow::on_pushButton_recherche_clicked()
{
 QString key = ui->lineEdit_recherche->text();
 abonnement A;
 QString cat = ui->cbrech->currentText();
 if (cat == "par ID")
    ui->tableView_ab->setModel(A.Rechercher_id(key));
 else if (cat == "par DUREE")
    ui->tableView_ab->setModel(A.Rechercher_duree(key));
 else if (cat == "par PRIX")
    ui->tableView_ab->setModel(A.Rechercher_prix(key));
 else
    { QMessageBox::critical(nullptr, QObject::tr("Introuvable"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);}
}

void Selim_MainWindow::on_pushButton_trier_clicked()
{ abonnement A;
 QString cat = ui->comboBox_trie->currentText();
         if (cat =="Durée")
            ui->tableView_ab->setModel(A.TrierDuree());
         else if (cat =="Prix")
            ui->tableView_ab->setModel(A.TrierPrix());
         else
             QMessageBox::critical(nullptr, QObject::tr("Erreur de trie"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void Selim_MainWindow::on_pushButton_clicked()
{ abonnement A;
    ui->tableView_ab->setModel(A.afficher_abonnement());
}



void Selim_MainWindow::on_pushButton_4_clicked()
{
    QString strStream;
        QTextStream out(&strStream); //eureur

          const int rowCount = ui->tableView_ab->model()->rowCount();
          const int columnCount = ui->tableView_ab->model()->columnCount();

          out <<  "<html>\n"
          "<head>\n"
          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           <<  QString("<title>%1</title>\n").arg("strTitle")
           <<  "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"

           //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des Abonnements </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

           // headers
           out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
           for (int column = 0; column < columnCount; column++)
           if (!ui->tableView_ab->isColumnHidden(column))
           out << QString("<th>%1</th>").arg(ui->tableView_ab->model()->headerData(column, Qt::Horizontal).toString());
           out << "</tr></thead>\n";

           // data table
           for (int row = 0; row < rowCount; row++) {
           out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
              for (int column = 0 ; column < columnCount; column++) {
              if (!ui->tableView_ab->isColumnHidden(column)) {
              QString data = ui->tableView_ab->model()->data(ui->tableView_ab->model()->index(row, column)).toString().simplified();
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








void Selim_MainWindow::on_tabWidget_tabBarClicked(int index)
{
        // CHARTS
    abonnement ab;
    QSqlQuery query;
    int i , qs;
    query.exec("select ID from ABONNEMENT");
    while(query.next()) qs = query.value(0).toInt();
    QPieSeries *series = new QPieSeries();

            for (i = 1; i< qs+1; i++) { series->append(QString::number(i), ab.percentage(QString::number(i)));
            }
            series->setLabelsVisible();


            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->legend()->hide();
            int j=0;
               for(auto slice : series->slices()) {  j++;
               slice->setLabel("Abonnement " + QString::number(j) + " :" + QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));}




           QChartView *chartview = new QChartView(chart);
            chartview->chart()->setTheme(QChart::ChartThemeDark);
            chart->setBackgroundBrush(QBrush(QColor(100, 100, 100)));
            chart->setAnimationOptions(QChart::AllAnimations);

           chartview->setParent(ui->stat);
           chartview->resize(780,450);

           // NOTIF
           ActiveAb n;
            ui->tab_renouv->setModel(n.afficher_notifs());
}

void Selim_MainWindow::on_pushButton_2_clicked()
{
    ActiveAb a;
    if(a.renouv(ui))
                  {
                      QMessageBox ::information(this,""," renouvelé!")  ;


                         ui->tab_renouv->setModel(a.afficher_notifs());

                  }
                  else{
                      QMessageBox ::critical(this,"","erreur!")  ;
}
}
