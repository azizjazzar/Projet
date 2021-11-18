#include "facture.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QBuffer>
#include <cstdlib>
#include <QImage>

Facture::Facture()
{
    reference="";
    nom="";
    prenom="";
    datee="";
}


Facture::Facture(QString reference,QString nom,QString prenom,QString datee)
{   this->reference=reference;
    this->nom=nom ;
    this->prenom=prenom;
    this->datee=datee ;

}

QString Facture::getreference(){return reference;}
QString Facture::getnom(){return nom;}
QString Facture::getprenom(){return prenom;}
QString Facture::getdatee(){return datee;}

void Facture::setreference(QString reference){this->reference=reference;}
void Facture::setnom(QString nom){this->nom=nom;}
void Facture::setprenom(QString prenom){this->prenom=prenom;}
void Facture::setdatee(QString datee){this->datee=datee;}

bool Facture::ajouter_facture()
{
    QSqlQuery query;
    query.prepare("INSERT INTO FACTURE (reference, nom, prenom,datee) "
                  "VALUES (:reference,:nom,:prenom,:datee)");
    query.bindValue(":reference", reference);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":datee", datee);
      return query.exec();
}



bool Facture::supprimer_facture(QString reference)
{
    QSqlQuery query;
    query.prepare("Delete from FACTURE where reference= :reference");
    query.bindValue(":reference", reference);
    return query.exec();
}

QSqlQueryModel* Facture::afficher_facture()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM FACTURE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datee"));
    return model;
}
bool Facture::modifier_facture(QString reference, QString Nom, QString Prenom, QString datee)
{    
    QSqlQuery query;
    query.prepare("update FACTURE set reference='"+reference+"', Nom='"+Nom+"',Prenom='"+Prenom+"',datee='"+datee+"' where reference=:reference ");
    query.bindValue(0, reference);
    query.bindValue(1, Nom);
    query.bindValue(2, Prenom);
    query.bindValue(3,datee);
    return query.exec();
}
QSqlQueryModel * Facture::rechercher_facture(QString SearchName)
{


        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * from FACTURE where reference LIKE '"+SearchName+"%'");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("datee"));
            return model;


}
QSqlQueryModel* Facture::tri_reference()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from FACTURE ORDER BY reference") ;
    query->exec() ;
    model->setQuery(*query) ;
    return model;

}
QSqlQueryModel* Facture::tri_date()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from FACTURE ORDER BY datee") ;
    query->exec() ;
    model->setQuery(*query) ;
    return model;

}
QSqlQueryModel* Facture::tri_nom()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from FACTURE ORDER BY nom") ;
    query->exec() ;
    model->setQuery(*query) ;
    return model;

}


