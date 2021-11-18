#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abonnement.h"
#include <QMessageBox>
#include <QIntValidator>

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
