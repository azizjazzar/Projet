#include "voyage.h"
#include <QDate>
#include  <QSqlQuery>
#include <QTDebug>
#include<QString>
#include <QObject>
Voyage::Voyage()
{

}
Voyage::Voyage (QString ref,int cin_chauffeur,QString matricule,QString etat,QString depart_bus,QString destination,QString date ,QString heure_depart,QString heure_arrive_prevu,QString heure_arrive)
{
 this ->ref=ref;
 this ->cin_chauffeur=cin_chauffeur;
 this ->matricule=matricule;
 this ->etat=etat;
 this ->date =date;
 this ->heure_arrive=heure_arrive;
 this ->heure_arrive_prevu=heure_arrive_prevu;
 this ->heure_depart=heure_depart;
 this->depart_bus=depart_bus;
 this ->destination=destination ;
}

bool Voyage::ajouter_voyage()
{

        QSqlQuery query;
        QString cin=QString::number(cin_chauffeur);
        query.prepare("INSERT INTO voyage (reference, cin_chauffeur, matricule,etat,date_d,heure_depart,heure_arrivep,heure_arrive,depart,destination) "
                      "VALUES (:reference, :cin_chauffeur, :matricule, :etat, :date_d, :heure_depart, :heure_arrivep, :heure_arrive, :depart, :destination)");
        query.bindValue(":reference", ref);
        query.bindValue(":cin_chauffeur", cin);
        query.bindValue(":matricule", matricule);
        query.bindValue(":etat", etat);
        query.bindValue(":depart", depart_bus);
        query.bindValue(":destination", destination);
        query.bindValue(":date_d", date);
        query.bindValue(":heure_depart",heure_depart);
        query.bindValue(":heure_arrivep", heure_arrive_prevu);
        query.bindValue(":heure_arrive",heure_arrive);
        return query.exec();

}
QSqlQueryModel * Voyage::afficher_voyage()
{
    QSqlQueryModel * model=new QSqlQueryModel();
      model->setQuery("SELECT* FROM voyage");
      return model;
}
bool Voyage::supprimer_voyage()
{
}
bool Voyage::modifier_voyage()
{
//MODIFIER
}

