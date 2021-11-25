#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abonnement.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <ui_mainwindow.h>
#include <QFile>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ abonnement A;
    ui->setupUi(this);
    ui->tableView_ab->setModel(A.afficher_abonnement());
    ui->spinBox_duree2->setRange(0,28);
    ui->spinBox_duree2_modif->setRange(0,28);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
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

void MainWindow::on_supprimer_clicked()
{
    abonnement supp;
    //QString i= ui->lineEdit_supprimer->text();
    //ui->lineEdit_supprimer->setText("");
    if(supp.supprimer_abonnement(ui))
                  {
                      QMessageBox ::information(this,"","supprimé!")  ;


                         ui->tableView_ab->setModel(supp.afficher_abonnement());

                  }
                  else{
                      QMessageBox ::critical(this,"","erreur!")  ;
    }
}

void MainWindow::on_pushButton_modifier_clicked()
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

void MainWindow::on_pushButton_recherche_clicked()
{
 QString ID = ui->lineEdit_recherche->text();
 abonnement A;
 ui->tableView_ab->setModel(A.Rechercher(ID));

}

void MainWindow::on_pushButton_trier_clicked()
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

void MainWindow::on_pushButton_clicked()
{ abonnement A;
    ui->tableView_ab->setModel(A.afficher_abonnement());
}

/*
// set dark background gradient:
QLinearGradient gradient(0, 0, 0, 400);
gradient.setColorAt(0, QColor(90, 90, 90));
gradient.setColorAt(0.38, QColor(105, 105, 105));
gradient.setColorAt(1, QColor(70, 70, 70));
customPlot->setBackground(QBrush(gradient));

// create empty bar chart objects:
QCPBars *active = new QCPBars(customPlot->xAxis, customPlot->yAxis);
QCPBars *inactive = new QCPBars(customPlot->xAxis, customPlot->yAxis);
regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
nuclear->setAntialiased(false);
fossil->setAntialiased(false);
regen->setStackingGap(1);
nuclear->setStackingGap(1);
fossil->setStackingGap(1);
// set names and colors:
fossil->setName("Fossil fuels");
fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
fossil->setBrush(QColor(111, 9, 176));
nuclear->setName("Nuclear");
nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
nuclear->setBrush(QColor(250, 170, 20));
regen->setName("Regenerative");
regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
regen->setBrush(QColor(0, 168, 140));
// stack bars on top of each other:
nuclear->moveAbove(fossil);
regen->moveAbove(nuclear);

// prepare x axis with country labels:
QVector<double> ticks;
QVector<QString> labels;
ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
labels << "Abonnement1" << "Abonnement2" << "Abonnement3" << "Abonnement4" << "Abonnement5" << "Abonnement6" << "Abonnement7";
QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
textTicker->addTicks(ticks, labels);
customPlot->xAxis->setTicker(textTicker);
customPlot->xAxis->setTickLabelRotation(60);
customPlot->xAxis->setSubTicks(false);
customPlot->xAxis->setTickLength(0, 4);
customPlot->xAxis->setRange(0, 8);
customPlot->xAxis->setBasePen(QPen(Qt::white));
customPlot->xAxis->setTickPen(QPen(Qt::white));
customPlot->xAxis->grid()->setVisible(true);
customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
customPlot->xAxis->setTickLabelColor(Qt::white);
customPlot->xAxis->setLabelColor(Qt::white);

// prepare y axis:
customPlot->yAxis->setRange(0, 12.1);
customPlot->yAxis->setPadding(5); // a bit more space to the left border
customPlot->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
customPlot->yAxis->setBasePen(QPen(Qt::white));
customPlot->yAxis->setTickPen(QPen(Qt::white));
customPlot->yAxis->setSubTickPen(QPen(Qt::white));
customPlot->yAxis->grid()->setSubGridVisible(true);
customPlot->yAxis->setTickLabelColor(Qt::white);
customPlot->yAxis->setLabelColor(Qt::white);
customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

// Add data:
QVector<double> fossilData, nuclearData, regenData;
fossilData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
fossil->setData(ticks, fossilData);
nuclear->setData(ticks, nuclearData);
regen->setData(ticks, regenData);

// setup legend:
customPlot->legend->setVisible(true);
customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
customPlot->legend->setBrush(QColor(255, 255, 255, 100));
customPlot->legend->setBorderPen(Qt::NoPen);
QFont legendFont = font();
legendFont.setPointSize(10);
customPlot->legend->setFont(legendFont);
customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);*/

void MainWindow::on_pushButton_4_clicked()
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
