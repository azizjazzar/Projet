#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <string>
#include "Selim_mainwindow.h"
class abonnement
{
private:
    QString ID;
    QString Duree;
    int Prix;
    //QDate Date;

public:
    abonnement();
    abonnement(QString ID,QString Duree,int Prix);

    bool ajouter_abonnement(QString,QString,int);
    bool modifier_abonnement(QString,QString,int);//Ui::Selim_MainWindow *ui);
    bool supprimer_abonnement(Ui::Selim_MainWindow *ui);
    bool set_duree(QString,QString);
    bool set_prix(QString,int);
    //bool supprimer_abonnement(QString i);
    QSqlQueryModel * afficher_abonnement();
    QSqlQueryModel * afficher_abonnement_d();
    QDate GetDateFin(QString);
    QSqlQueryModel * Rechercher_id(QString);
    QSqlQueryModel * Rechercher_duree(QString);
    QSqlQueryModel * Rechercher_prix(QString);
    QSqlQueryModel * TrierDuree();
    QSqlQueryModel * TrierPrix();
    float percentage(QString);

};

#endif // ABONNEMENT_H
