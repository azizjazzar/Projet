#ifndef VOYAGE_H
#define VOYAGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>


class Voyage
{
private:
    QString ref,depart_bus,destination,etat;
    QString  matricule ;
    QString date , heure_depart,heure_arrive,heure_arrive_prevu;
    int cin_chauffeur;

public:
    //Constructeurs
    Voyage();
    // Voyage(QString,QString,QString,QString,QDate,QTime,QTime,QTime,QString,QString);
    Voyage (QString ref,int cin_chauffeur,QString matricule,QString etat,QString depart_bus,QString destination,QString date ,QString heure_depart,QString heure_arrive_prevu,QString heure_arrive);

    //Fonctionnalités CRUDs_voyage
    bool ajouter_voyage();
    bool modifier_voyage();
    bool supprimer_voyage();
    QSqlQueryModel * afficher_voyage();
};

#endif // VOYAGE_H
