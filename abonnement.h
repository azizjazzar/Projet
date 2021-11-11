#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <ui_mainwindow.h>

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
    bool modifier_abonnement(QString,QString,int);//Ui::MainWindow *ui);
    bool supprimer_abonnement(Ui::MainWindow *ui);
    bool set_duree(QString,QString);
    bool set_prix(QString,int);
    //bool supprimer_abonnement(QString i);
    QSqlQueryModel * afficher_abonnement();

};

#endif // ABONNEMENT_H
