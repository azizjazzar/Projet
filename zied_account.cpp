#include "zied_account.h"
#include "ui_zied_account.h"
#include "zied_employe.h"
#include <QMessageBox>
#include <QDebug>
account::account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::account)
{
    ui->setupUi(this);
    ui->ajout_cin->setReadOnly(true);
    ui->ajout_nom->setReadOnly(true);
    ui->ajout_prenom->setReadOnly(true);
    ui->ajout_num->setReadOnly(true);
    ui->ajout_date->setReadOnly(true);
    ui->ajout_role->setReadOnly(true);
    ui->ajout_email->setReadOnly(true);
    ui->ajout_login->setReadOnly(true);
    ui->ajout_password->setReadOnly(true);
    switch(a.connect_arduino())
    {
        case (0):
            qDebug()<<"arduino is available and connected to"<<a.get_arduino_port_name();
        break;
        case (1):
            qDebug()<<"arduino is available but not connected to"<<a.get_arduino_port_name();
        break;
        case (-1):
            qDebug()<<"arduino is not available";
        break;

    }

    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

account::~account()
{
    delete ui;
}

void account::set(employe a)
{
    e=a;
    ui->ajout_cin->setText(e.get_cin());
    ui->ajout_nom->setText(e.get_nom());
    ui->ajout_prenom->setText(e.get_prenom());
    QString S=QString::fromStdString(to_string(e.get_num()));
    ui->ajout_num->setText(S);
    ui->ajout_date->setDate(e.get_date());
    ui->ajout_role->setText(e.get_role());
    ui->ajout_email->setText(e.get_email());
    ui->ajout_login->setText(e.get_login());
    ui->ajout_password->setText(e.get_password());
    ui->tableView->setModel(e.emploi());
    if(e.get_role()=="chauffeur")
        valid=true;
}


void account::update_label()
{

    data=a.read_from_arduino();
    if((data.toStdString()=="1")&&(valid))
    {
        QSqlQuery query;
        QSqlQueryModel *model=new QSqlQueryModel();
        QString i;
        query.prepare("select reference from voyage where cin_chauffeur= :cin AND (extract(year from heure_arrivep))= :year  AND (extract(month from heure_arrivep))= :month AND (extract(day from heure_arrivep))>= :day AND etat= :etat order by heure_depart");
        QDate d=d.currentDate();
        int year,month,day;
        d.getDate(&year,&month,&day);
        query.bindValue(":year",year);
        query.bindValue(":month",month);
        query.bindValue(":day",day);
        query.bindValue(":cin",e.get_cin());
        query.bindValue(":etat","plannifier");
        if(query.exec())
        {
            model->setQuery(query);
            i=model->data(model->index(0,0)).toString();
            query.prepare("select heure_arrivep from voyage where reference= :ref order by heure_depart");
            query.bindValue(":ref",i);
            if((query.exec())&&(i!=""))
            {
               model->setQuery(query);
               QDateTime d2=d2.currentDateTime();
               qDebug()<<d2<<">"<<model->data(model->index(0,0)).toDate();
               if(model->data(model->index(0,0)).toDateTime()<d2)
               {
                   query.prepare("update voyage set etat= :etat,heure_arrive= :date where reference= :ref");
                   query.bindValue(":etat","en retard");
                   query.bindValue(":date",d2);
                   query.bindValue(":ref",i);
                   if(query.exec())
                   {
                       data="2";
                       QMessageBox::critical(nullptr,QObject::tr("database updated"),QObject::tr("profile has been refreshed.\nyou arrived a bit late."),QMessageBox::Cancel);
                       a.write_to_arduino(data);
                   }
               }
               else
               {
                   query.prepare("update voyage set etat= :etat,heure_arrive= :date where reference= :ref");
                   query.bindValue(":etat","terminner");
                   query.bindValue(":date",d);
                   query.bindValue(":ref",i);
                   if(query.exec())
                   {
                       data="3";
                       QMessageBox::information(nullptr,QObject::tr("database updated"),QObject::tr("profile has been refreshed.\nyou arrived just on time."),QMessageBox::Ok);
                       a.write_to_arduino(data);
                   }
               }
            }

        ui->tableView->setModel(e.emploi());
        }
    }
}



