#include "mikhail_facture.h"
#include "ui_mikhail_facture.h"
#include <QMessageBox>
#include <QPixmap>
#include"smtp.h"
#include <QFileDialog>
#include <QPrinter>
#include<QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QDateTime>
#include<QTimer>
#include<QBarSet>
#include<QBarSeries>
#include <QtCharts>
#include <QChartView>
#include "notepad.h"
#include <QIntValidator>
mikhail_facture::mikhail_facture(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mikhail_facture)
{
    ui->setupUi((QDialog*)this);
    ui->tab_facture->setModel(tmp_facture.afficher_facture());
QIntValidator *val=new QIntValidator(0,99999999,this);
ui->reference->setValidator(val);
    int ret=a.connect_arduino();
         switch (ret) {
         case(0):qDebug()<<"arduino is available and connected to :"<<a.get_arduino_port_name();
             break;
         case(1):qDebug()<<"arduino is available but not connected to :"<<a.get_arduino_port_name();
             break;
         case(-1):qDebug()<<"arduino is not available";
         }
   QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));//signal arduino



    PixTrueIcon=QPixmap("C:/Users/MSI GF63/Desktop/Atelier_Connexion/True_icon.jpg");
    PixFalseIcon=QPixmap("C:/Users/MSI GF63/Desktop/Atelier_Connexion/False_icon.png");
    QSqlQuery queryD;
    int countD=0 ;
    QSqlQuery requeteD("select * from facture where substr(datee,7,4)||'-'||substr(datee,1,2)||'-'||substr(datee,4,2) <= '2020-01-01'") ;
    while(requeteD.next())
    {
           countD++ ;
    }

    QSqlQuery query1D;
     int count1D=0 ;
     QSqlQuery requete1D("select * from facture where substr(datee,7,4)||'-'||substr(datee,1,2)||'-'||substr(datee,4,2) >= '2021-01-01'") ;
     while(requete1D.next())
     {
             count1D++ ;
     }
     QBarSet *set0D= new QBarSet(" Nombre des facture de init a 2020");
     QBarSet *set1D= new QBarSet("Nombre des facture de 2021");


                 *set0D <<countD ;
                 *set1D<<count1D;

                 QBarSeries *seriesD= new QBarSeries();
                   seriesD->append(set0D);
                     seriesD->append(set1D);


                QChart * chartD =new QChart();
                   chartD-> addSeries(seriesD);
                   chartD->setTitle("Statistiques des factures par tranche ");
                   chartD->setAnimationOptions(QChart::SeriesAnimations);
                 QStringList categoriesD;
                 QBarCategoryAxis *axisD= new QBarCategoryAxis();
                 axisD->append(categoriesD);
                 chartD->createDefaultAxes();
                 chartD->setAxisX(axisD,seriesD);




                 QChartView *chartviewD= new QChartView (chartD);
                  chartviewD->setParent(ui->frame_charts_2);


}

mikhail_facture::~mikhail_facture()
{
    delete ui;
}
void mikhail_facture::update_label()
{
data.append(a.read_from_arduino());
qDebug()<<data;
if (data.length() == 8)
  {
    if(tmp_facture.rech(data.toInt())){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("facture trouvé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    data.clear();}
        else {
            QMessageBox::critical(nullptr, QObject::tr("introuvable"),
                        QObject::tr("facture non trouvé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
             data.clear();

        }

}
}
bool mikhail_facture::verif_reference()
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
bool mikhail_facture::verif_nom()
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
bool mikhail_facture::verif_prenom()
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
bool mikhail_facture::verif_date()
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




void mikhail_facture::on_ajouter_facture_clicked()
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


void mikhail_facture::on_modifier_facture_clicked()
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


void mikhail_facture::on_supprimer_facture_clicked()
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


void mikhail_facture::on_afficher_clicked()
{
    ui->tab_facture->setModel(tmp_facture.afficher_facture());

}



void mikhail_facture::on_tab_facture_activated(const QModelIndex &index)
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



void   mikhail_facture::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::information(nullptr, tr( "Envoi par mail" ), tr( "Votre facture a été payée  !\n\n" ) );
    ui->rcpt_2->clear();
    ui->Objet_2->clear();
    ui->file_2->clear();
    ui->Texte_2->clear();

    hide();

    QFile file("C:/Users/user/Desktop/mikhail/PdfAbonnes.pdf");
   file.remove();

}
void mikhail_facture::on_email_clicked()
{
    ui->stackedWidget1->setCurrentIndex(1);

}

void mikhail_facture::on_sendBtn_2_clicked()
{
    smtp *s=new smtp("mikhail.mannai@esprit.tn","jesuismikhail","smtp.gmail.com",465);
    s->sendMail("mikhail.mannai@esprit.tn", ui->rcpt_2->text() , ui->Objet_2->text(), ui->Texte_2->toPlainText(), files );
    QMessageBox::information(nullptr,QObject::tr("Ok"),
                         QObject::tr("Mail envoyé\n"
                                       "Click cancel to exit."),QMessageBox::Cancel);
}

void mikhail_facture::on_browseBtn_2_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory("C:/Users/MSI GF63/Desktop/");
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file_2->setText(fileListString);
}

void mikhail_facture::on_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/MSI GF63/Desktop/PdfAbonnes.pdf");
         QPainter painter(&pdf);
         int i = 4000;
         painter.setPen(Qt::black);
         painter.setFont(QFont("Arial", 30));
         painter.drawText(2300,1200,"Liste Des Factures ");
         painter.setPen(Qt::black);
         painter.setFont(QFont("Arial", 50));
        //painter.drawText(1100,2000,afficheDC);
         painter.drawRect(1500,200,7300,2600);
         //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
         painter.drawRect(0,3000,9600,500);
         painter.setFont(QFont("Arial", 9));
         painter.drawText(300,3300,"reference");
         painter.drawText(2300,3300,"nom");
         painter.drawText(4300,3300,"prenom");
         painter.drawText(6300,3300,"Date");
         QSqlQuery query;
         query.prepare("select * from FACTURE");
         query.exec();
         while (query.next())
         {
             painter.drawText(300,i,query.value(0).toString());
             painter.drawText(2300,i,query.value(1).toString());
             painter.drawText(4300,i,query.value(2).toString());
             painter.drawText(6300,i,query.value(3).toString());

             i = i +500;
         }
         int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
         if (reponse == QMessageBox::Yes)
         {
             QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/MSI GF63/Desktop/PdfAbonnes.pdf"));

             painter.end();
         }
         if (reponse == QMessageBox::No)
         {
             painter.end();
         }
}

void mikhail_facture::on_pushButton_clicked()
{
    ui->stackedWidget1->setCurrentIndex(0);

}

void mikhail_facture::on_stat_clicked()
{
    ui->stackedWidget1->setCurrentIndex(2);

}

void mikhail_facture::on_return_3_clicked()
{
    ui->stackedWidget1->setCurrentIndex(0);

}


void mikhail_facture::on_notepad_clicked()
{


}

void mikhail_facture::on_trier_facture_clicked()
{
    QString type = ui->comboBox_facture->currentText();
     if (type == "reference")
     {
         ui->tab_facture->setModel(tmp_facture.tri_reference());
     }/*else if (type == "date")
     {
         ui->tab_facture->setModel(tmp_facture.tri_date());

     }
     else if(type=="nom")
     {
         ui->tab_facture->setModel(tmp_facture.tri_nom());
     }*/
}



void mikhail_facture::on_recherche_facture_textChanged(const QString &arg1)
{
    ui->tab_facture->setModel(tmp_facture.rechercher_facture(arg1));
}
