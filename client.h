#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include "connection.h"
#include <cstdio>
#include <QFile>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPointF>
/*
typedef struct dates
{
int day;
int mounth;
int year;
}dates;
*/

class Client
{
public:
    //constructeurs
    Client();
    Client(QString id,QString nom,QString prenom,QString adresse,QString genre,QString date_nais);
    //get
    QString getid();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QString getgenre();
    QString getdate_nais();
    //set
    void setid(QString id);
    void setnom(QString nom);
    void setprenom(QString prenom);
    void setadresse(QString adresse);
    void setgenre(QString genre);
    void setdate_nais(QString date_nais);
    void setdate_enrg(QString date_enrg);
    //Crud
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer();
    bool update();
    QSqlQueryModel * trie(QString);
    QSqlQueryModel * recherche();
    QSqlQueryModel * autoremplisage();
    bool supprimer_innactif();
    QSqlQuery chercher();
    QString  recherchee();
    int calculenfant();
    int calculpersonneage();
    int calculadulte();
    int homme(QDate datenom);
    int femme(QDate datenom);
    bool carte_mag();
private:
    QString id;
    QString nom ;
    QString prenom;
    QString adresse;
    QString date_nais;
    QString genre;
    QString date_enrg;



};

#endif // CLIENT_H
