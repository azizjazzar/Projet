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


   void setreference(QString reference);
   void setnom(QString nom);
   void setprenom(QString prenom);
   void setdatee(QString datee);
   bool ajouter_facture() ;
   QSqlQueryModel* afficher_facture();
   bool supprimer_facture(QString);
   bool modifier_facture(QString,QString,QString,QString);

private:
   QString reference="";
    QString nom="";
    QString prenom="";
   QString datee="";

};

#endif // FACTURE_H
