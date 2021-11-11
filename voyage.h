#ifndef VOYAGE_H
#define VOYAGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class Voyage
{
private:
    QString ref,depart_bus,destination,etat;
    QString  matricule ;
    QString date , heure_depart,heure_arrive,heure_arrive_prevu,cin_chauffeur;


public:
    //Constructeurs
    Voyage();
    Voyage (QString ref,QString cin_chauffeur,QString matricule,QString etat,QString depart_bus,QString destination,QString date ,QString heure_depart,QString heure_arrive_prevu,QString heure_arrive);

    //Fonctionnalités CRUDs_voyage
    bool ajouter_voyage();
    bool modifier_voyage();
    bool supprimer_voyage(QString ref);
    QSqlQueryModel * afficher_voyage();
    QString get_ref();
    void set_ref(QString r);
};

#endif // VOYAGE_H
