#include "gestionvoyage.h"
#include "ui_gestionvoyage.h"
#include "voyage.h"
#include <QSqlQueryModel>
#include  <QSqlQuery>
#include <QTDebug>
#include <QString>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
gestionvoyage::gestionvoyage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestionvoyage)
{
    ui->setupUi(this);
    ui->tab_voyage->setModel(V.afficher_voyage());
}

gestionvoyage::~gestionvoyage()
{
    delete ui;
}

void gestionvoyage::on_pushButton_ok_clicked()
{
bool ok;
    QString ref=ui->lineEdit_ref->text();
    QString cin=ui->lineEdit_chauf->text();
    QString matricule=ui->lineEdit_matricule->text();
    QString etat=ui->comboBox_etat->currentText();
    QString depart=ui->comboBox_ligne->currentText();
    QString destination=ui->comboBox_dest->currentText();
    QString date=ui->dateEdit->text();
    QString heure_depart=ui->timeEdit_depart->text();
    QString heure_arrive=ui->timeEdit_arrive2->text();
    QString heure_arrive_prevu=ui->timeEdit_arrive1->text();

    Voyage V(ref,cin,matricule,etat,depart,destination,date , heure_depart,heure_arrive_prevu,heure_arrive);

    ok=V.ajouter_voyage();

    if (ok)
    {ui->tab_voyage->setModel(V.afficher_voyage());
        QMessageBox::information(nullptr, QObject::tr("voyage ajouté"),
                    QObject::tr("voyage ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("impossible d'ajouter le voyage"),
                    QObject::tr("impossible d'ajouter le voyage.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionvoyage::on_pushButton_supprimer_clicked()
{
  bool test=V.supprimer_voyage(val);

  if (test)
  {
      ui->tab_voyage->setModel(V.afficher_voyage());
      val="";
      qDebug()<<val<<endl;
      QMessageBox::information(nullptr, QObject::tr("voyage supprimé"),
                  QObject::tr("voyage supprimé.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("impossible de supprimer le voyage"),
                  QObject::tr("impossible de supprimer le voyage.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void  gestionvoyage::on_tab_voyage_activated(const QModelIndex &index)
{
     val=ui->tab_voyage->model()->data(index).toString();
     qDebug()<<val;

}

void gestionvoyage::on_pushButton_modifier_clicked()
{
    QSqlQuery query;

        query.prepare("select * from voyage where reference='"+val+"'  ");

      if (query.exec())
         {
             while (query.next())
             {  //ui->pushButton_ok->setText("modifier");
                 ui->lineEdit_ref->setText(query.value(0).toString());
                 ui->lineEdit_chauf->setText(query.value(1).toString());
                 ui->lineEdit_matricule->setText(query.value(2).toString());
                 ui->comboBox_etat->setCurrentText(query.value(3).toString());
                 ui->dateEdit->setDate(query.value(4).toDate());
                 ui->timeEdit_depart->setTime(query.value(5).toTime());
                 ui->timeEdit_arrive1->setTime(query.value(6).toTime());
                 ui->timeEdit_arrive2->setTime(query.value(7).toTime());
                 ui->comboBox_ligne->setCurrentText(query.value(8).toString());
                 ui->comboBox_ligne->setCurrentText(query.value(9).toString());



             }

         }
      else {qDebug()<<"failed";}

}

void gestionvoyage::on_pushButton_modifierr_clicked()
{
   bool ok;
   QString ref=ui->lineEdit_ref->text();
   QString cin=ui->lineEdit_chauf->text();
   QString matricule=ui->lineEdit_matricule->text();
   QString etat=ui->comboBox_etat->currentText();
   QString depart=ui->comboBox_ligne->currentText();
   QString destination=ui->comboBox_dest->currentText();
   QString date=ui->dateEdit->text();
   QString heure_depart=ui->timeEdit_depart->text();
   QString heure_arrive=ui->timeEdit_arrive2->text();
   QString heure_arrive_prevu=ui->timeEdit_arrive1->text();
    Voyage V(ref,cin,matricule,etat,depart,destination,date , heure_depart,heure_arrive_prevu,heure_arrive);

    ok=V.modifier_voyage();

    if (ok)
    {ui->tab_voyage->setModel(V.afficher_voyage());
        QMessageBox::information(nullptr, QObject::tr("voyage modifié"),
                    QObject::tr("voyage modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("impossible de modifier le voyage"),
                    QObject::tr("impossible de modifier le voyage.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionvoyage::on_pushButton_clicked()
{    QDate Date=QDate::fromString("11/11/2021","MM/dd/yyyy");
    ui->lineEdit_ref->clear();
    ui->lineEdit_chauf->clear();
    ui->lineEdit_matricule->clear();
    ui->dateEdit->setDate(Date);
    val="";
     r=0;
      ui->tab_voyage->setModel(V.afficher_voyage());
      qDebug()<<r;
}

void gestionvoyage::on_pushButton_annuler_clicked()
{  QDate Date=QDate::fromString("11/11/2021","MM/dd/yyyy");
    ui->lineEdit_ref->clear();
    ui->lineEdit_chauf->clear();
    ui->lineEdit_matricule->clear();
    ui->dateEdit->setDate(Date);
}

void gestionvoyage::on_pushButton_rechercher_clicked()
{
  Voyage V;
  r=1;
ui->tab_voyage->setModel(V.rechercher(ui->comboBox_choix->currentText().toStdString(),ui->lineEdit_val->text(),ui->comboBox_etat_2->currentText()));
qDebug()<<r;
ui->lineEdit_val->clear();
ui->comboBox_choix->setCurrentText("Reference ");
ui->comboBox_etat_2->setCurrentText("Tous");
}

void gestionvoyage::on_pushButton_trier_clicked()
{
    Voyage V;
    r=1;
    ui->tab_voyage->setModel(V.trier(ui->comboBox_Tpar->currentText().toStdString(),ui->comboBox_Tordre->currentText().toStdString()));
    qDebug()<<r;
}

void gestionvoyage::on_pushButton_ok_2_clicked()
{
   Voyage v;
  v.exporter_PDF(ui->comboBox_exporter->currentText().toStdString());
}

void gestionvoyage::on_pushButton_annuler_2_clicked()
{
  Voyage v;
v.exporter_excel(ui->comboBox_exporter->currentText().toStdString());
}

void gestionvoyage::on_pushButton_2_clicked()
{
   Voyage v;
   ui->tableView->setModel(v.list_clients(ui->lineEdit->text()));
   ui->lineEdit->clear();
}
