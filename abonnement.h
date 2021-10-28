#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>

class abonnement
{
public:

    abonnement();
    abonnement(QString ID,QString type,QString Duree,int Prix);

    bool ajouter_abonnement();
    bool modifier_abonnement();
    bool supprimer_abonnement();
    QSqlQueryModel * afficher_abonnement();
private:
    QString ID,type;
    int Prix;
    //QDate
    QString Duree;
};

#endif // ABONNEMENT_H
