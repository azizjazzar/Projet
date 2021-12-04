#include "zied_mainwindow.h"
#include "ui_mainwindow.h"
#include "zied_employe.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QPainter>
#include <QPdfWriter>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QtPrintSupport>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    employe e;
    QString s;
    ui->tableView->setModel(e.affichier());
    QPieSeries *series=new QPieSeries();
    series->append("Responsable resourse humaine",e.RRH());
    series->append("chauffeur",e.chauffeur());
    series->append("other",e.other());
    series->slices().at(0)->setLabelVisible();
    series->slices().at(1)->setLabelVisible();
    series->slices().at(2)->setLabelVisible();
    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("statistic");
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->frame);
    chartview->setFixedSize(ui->frame->size());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chart()
{
    employe e;
    QPieSeries *series=new QPieSeries();
    series->append("Responsable resourse humaine",e.RRH());
    series->append("chauffeur",e.chauffeur());
    series->append("other",e.other());
    series->slices().at(0)->setLabelVisible();
    series->slices().at(1)->setLabelVisible();
    series->slices().at(2)->setLabelVisible();
    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("statistic");
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->frame);
    chartview->setFixedSize(ui->frame->size());
    chartview->show();
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
   e.ajouter();
   /*bool test=e.ajouter();
   if(test)
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
   chart();
}

void MainWindow::on_pushButton_supp_clicked()
{
    employe e;
    e.supprimer(ui->cin_mod->text());
    ui->tableView->setModel(e.affichier());
    ui->cin_mod->setText("");
    chart();

}

void MainWindow::on_pushButton_mod_clicked()
{
    employe e;
    e.modifier(ui->attribut_mod->currentText().toStdString(),ui->mod_val->text(),ui->cin_mod->text());
    ui->tableView->setModel(e.affichier());
    ui->cin_mod->setText("");
    ui->mod_val->setText("");
    chart();
}

void MainWindow::on_pushButton_aff_clicked()
{
    employe e;
    ui->tableView->setModel(e.affichier());
    chart();
}

void MainWindow::on_pushButton_9_clicked()
{
    employe e;
    ui->tableView->setModel(e.rechercher(ui->lineEdit_15->text(),ui->comboBox_5->currentText().toStdString()));
}

void MainWindow::on_pushButton_11_clicked()
{
    employe e;
    ui->tableView->setModel(e.tri(ui->comboBox_7->currentText().toStdString(),ui->comboBox_8->currentText().toStdString()));
}

void MainWindow::on_pushButton_8_clicked()
{
    employe e(ui->lineEdit_14->text());
    ui->tableView->setModel(e.emploi());
}


void MainWindow::on_pushButton_2_clicked()
{
    employe e;
    QPieSeries *series=new QPieSeries();
    series->append("Responsable resourse humaine",e.RRH());
    series->append("chauffeur",e.chauffeur());
    series->append("other",e.other());
    series->slices().at(0)->setLabelVisible();
    series->slices().at(1)->setLabelVisible();
    series->slices().at(2)->setLabelVisible();
    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setTitle("statistic");
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->frame);
    chartview->setFixedSize(ui->frame->size());
    QFrame *widget=ui->frame;
    QPixmap pix(widget->size());
      QPainter painter(&pix);
      widget->render(&painter);
      painter.end();
      QPrinter printer(QPrinter::HighResolution);
      printer.setOrientation(QPrinter::Landscape);
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setPaperSize(QPrinter::A4);
      const QString &string=ui->lineEdit->text()+"/statistique.pdf";
      printer.setOutputFileName(string);

      if(painter.begin(&printer))
      {
      double xscale = printer.pageRect().width() / double(pix.width());
      double yscale = printer.pageRect().height() / double(pix.height());
      double scale = qMin(xscale, yscale);
      painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                        printer.paperRect().y() + printer.pageRect().height() / 2);
      painter.scale(scale, scale);
      painter.translate(-widget->width() / 2, -widget->height() / 2);
      painter.drawPixmap(0, 0, pix);

    QTextDocument doc;

    doc.setHtml("");
    doc.drawContents(&painter);

      painter.end();
      }
      else
          QMessageBox::critical(nullptr,QObject::tr("Operation failed!!!"),QObject::tr("Invalid file destination."),QMessageBox::Retry);
      ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText("C:/Users/zied loukil/OneDrive/Documents/maquette");
}
