#include "voyage.h"
#include  <QSqlQuery>
#include <QTDebug>
#include<QString>
#include <QObject>
#include <QDate>
Voyage::Voyage()
{
     ref="";
     cin_chauffeur="";
     etat="";
     date="";
     heure_arrive="";
     heure_depart="";
     heure_arrive_prevu="";
     destination="";
     depart_bus="";

}
Voyage::Voyage (QString ref,QString cin_chauffeur,QString matricule,QString etat,QString depart_bus,QString destination,QString date ,QString heure_depart,QString heure_arrive_prevu,QString heure_arrive)
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
QString Voyage::get_ref()
{
    return  ref;
}
void Voyage::set_ref(QString r)
{
      ref=r;
}
bool Voyage::ajouter_voyage()
{

        QSqlQuery query;

        QDate Date=QDate::fromString(date,"MM/dd/yyyy");
        QTime depart=QTime::fromString(heure_depart,"h:mm AP");
        QTime arrivep=QTime::fromString(heure_arrive_prevu,"h:mm AP");
       QTime arrive=QTime::fromString(heure_arrive,"h:mm AP");
        query.prepare("INSERT INTO voyage (reference, cin_chauffeur, matricule,etat,date_d,heure_depart,heure_arrivep,heure_arrive,depart,destination) "
                      "VALUES (:reference, :cin_chauffeur, :matricule, :etat, :date_d, :heure_depart, :heure_arrivep, :heure_arrive, :depart, :destination)");
        query.bindValue(":reference", ref);
        query.bindValue(":cin_chauffeur", cin_chauffeur);
        query.bindValue(":matricule", matricule);
        query.bindValue(":etat", etat);
        query.bindValue(":depart", depart_bus);
        query.bindValue(":destination", destination);
        query.bindValue(":date_d", Date);
        query.bindValue(":heure_depart",depart);
        query.bindValue(":heure_arrivep", arrivep);
        query.bindValue(":heure_arrive",arrive);
        return query.exec();

}
QSqlQueryModel * Voyage::afficher_voyage()
{
    QSqlQueryModel * model=new QSqlQueryModel();
      model->setQuery("SELECT* FROM voyage");
      return model;
}

bool Voyage::supprimer_voyage(QString reff)
{
  if (reff!="")
    {QSqlQuery query ;
    query.prepare("Delete from voyage where reference= :reference");
    query.bindValue(0,reff);
    return  query.exec();}

}

bool Voyage::modifier_voyage( )
{

    QSqlQuery query;

 QDate Date=QDate::fromString(date,"MM/dd/yyyy");
 QTime depart=QTime::fromString(heure_depart,"h:mm AP");
 QTime arrivep=QTime::fromString(heure_arrive_prevu,"h:mm AP");
 QTime arrive=QTime::fromString(heure_arrive,"h:mm AP");
 query.prepare("UPDATE voyage set cin_chauffeur=:cin_chauffeur, matricule=:matricule,etat=:etat,date_d=:date_d,heure_depart=:heure_depart,heure_arrivep=:heure_arrivep,heure_arrive=:heure_arrive,depart=:depart,destination= :destination where reference= :reference");

    query.bindValue(":reference", ref);
    query.bindValue(":cin_chauffeur", cin_chauffeur);
    query.bindValue(":matricule", matricule);
    query.bindValue(":etat", etat);
    query.bindValue(":depart", depart_bus);
    query.bindValue(":destination", destination);
    query.bindValue(":date_d", Date);
    query.bindValue(":heure_depart",depart);
    query.bindValue(":heure_arrivep", arrivep);
    query.bindValue(":heure_arrive",arrive);
    return query.exec();
}

