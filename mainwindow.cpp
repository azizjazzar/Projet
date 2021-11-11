#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_facture->setModel(tmp_facture.afficher_facture());




    PixTrueIcon=QPixmap("C:/Users/MSI GF63/Desktop/Atelier_Connexion/True_icon.jpg");
    PixFalseIcon=QPixmap("C:/Users/MSI GF63/Desktop/Atelier_Connexion/False_icon.png");
    background=QPixmap("C:/Users/MSI GF63/Desktop/Atelier_Connexion/istockphoto-1135638647-170667a.jpg");
    ui->label_background->setPixmap(background);


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::verif_reference()
{
    if (ui->reference->text().isEmpty())
    {
        ui->reference->clear();

        ui->label_reference->setPixmap(PixFalseIcon);
        ui->reference->setPlaceholderText("contient que des caracteres") ;
        return false;
    }else
    {
        ui->label_reference->setPixmap(PixTrueIcon);
        return true;
    }
}
bool MainWindow::verif_nom()
{
    if ( ui->nom->text().isEmpty())
    {
        ui->nom->clear();

        ui->label_nom->setPixmap(PixFalseIcon);
        ui->nom->setPlaceholderText("Le ID est vide") ;

        return false;
    }else
    {
        ui->label_nom->setPixmap(PixTrueIcon);
        return true;
    }
}
bool MainWindow::verif_prenom()
{
    if ( ui->prenom->text().isEmpty())
    {
        ui->prenom->clear();

        ui->label_prenom->setPixmap(PixFalseIcon);
        ui->prenom->setPlaceholderText("contient que des caracteres") ;

        return false;
    }else
    {
        ui->label_prenom->setPixmap(PixTrueIcon);
        return true;
    }
}
bool MainWindow::verif_date()
{
    if (ui->date->date().isValid())
    {
        ui->date->clear();

        ui->label_date->setPixmap(PixTrueIcon);

        return true;
    }else
    {
        ui->label_date->setPixmap(PixFalseIcon);
        return false;
    }
}




void MainWindow::on_ajouter_facture_clicked()
{
    QString reference=ui->reference->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QDate dateP=ui->date->date();
    QString datePl= dateP.toString("dd/MM/yyyy");
    QMessageBox msgBox;

    Facture c(reference, nom, prenom,datePl);
    if( verif_reference() && verif_nom() && verif_prenom() && verif_date())
    {
    bool test=c.ajouter_facture();


    if(test)
    { msgBox.setText("Ajout avec succés");
        ui->tab_facture->setModel(tmp_facture.afficher_facture());
    }
}
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}


void MainWindow::on_modifier_facture_clicked()
{
    QString reference=ui->reference->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QDate dateP=ui->date->date();
   QString datePl= dateP.toString("dd/MM/yyyy");
   QMessageBox msgBox;
  Facture c(reference, nom, prenom,datePl);
  bool test=c.modifier_facture(reference,nom,prenom,datePl);

    if(test)
    {
        msgBox.setText("Modification avec succés");
        ui->tab_facture->setModel(tmp_facture.afficher_facture());
    }
    else
        msgBox.setText("Echec de modification");
        msgBox.exec();
}


void MainWindow::on_supprimer_facture_clicked()
{
    QString reference=ui->reference->text();
    bool test=tmp_facture.supprimer_facture(reference);
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Supprission avec succés");
        ui->tab_facture->setModel(tmp_facture.afficher_facture());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}


void MainWindow::on_afficher_clicked()
{
    ui->tab_facture->setModel(tmp_facture.afficher_facture());

}



void MainWindow::on_tab_facture_activated(const QModelIndex &index)
{
    QString val=ui->tab_facture->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select* from FACTURE where reference='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->reference->setText(query.value(0).toString());
            ui->nom->setText(query.value(1).toString());
            ui->prenom->setText(query.value(2).toString());
            ui->date->setDate(query.value(3).toDate());


           }
    }
}



