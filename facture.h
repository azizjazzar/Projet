#ifndef FACTURE_H
#define FACTURE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class Facture
{
public:
    Facture();
    Facture(QString reference,QString nom,QString prenom,QString datee);



   QString getreference();
   QString getnom();
   QString getprenom();
   QString getdatee();

bool rech(int ref);
   void setreference(QString reference);
   void setnom(QString nom);
   void setprenom(QString prenom);
   void setdatee(QString datee);
   bool ajouter_facture() ;
   QSqlQueryModel* afficher_facture();
   bool supprimer_facture(QString);
   bool modifier_facture(QString,QString,QString,QString);
   QSqlQueryModel * rechercher_facture(QString);
       QSqlQueryModel* tri_reference() ;
       QSqlQueryModel *tri_date();
        QSqlQueryModel *tri_nom();

private:
   QString reference="";
    QString nom="";
    QString prenom="";
   QString datee="";

};

#endif // FACTURE_H
