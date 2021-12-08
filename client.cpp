#include "client.h"
#include "connection.h"
#include <QMessageBox>
#include <QFile>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPointF>
#include <iostream>

//constructeurs
Client::Client()
{
id="";
nom="";
prenom="";
genre="";
adresse="";
date_nais="";


}
Client::Client(QString id,QString nom,QString prenom,QString adresse,QString genre,QString date_nais)
{
this->id=id;
this->nom=nom;
this->prenom=prenom;
this->adresse=adresse;
this->genre=genre;
this->date_nais=date_nais;
}

//get

QString Client::getid()
{
   return id;
}
QString Client::getnom()
{
   return nom;
}
QString Client::getprenom()
{
   return prenom;
}
QString Client::getadresse()
{
   return adresse;
}
QString Client::getgenre()
{
   return genre;
}
QString Client::getdate_nais()
{
   return date_nais;
}

//set

void Client::setid(QString id)
{
this->id=id;
}
void Client::setnom(QString nom)
{
this->nom=nom;
}
void Client::setprenom(QString prenom)
{
this->prenom=prenom;
}
void Client::setadresse(QString adresse)
{
this->adresse=adresse;
}
void Client::setgenre(QString genre)
{
this->genre=genre;
}
void Client::setdate_nais(QString date_nais)
{
this->date_nais=date_nais;
}
void Client::setdate_enrg(QString date_enrg)
{
this->date_enrg=date_enrg;
}

//crud
bool Client::ajouter()
{
QSqlQuery query;
QDate datecurent=QDate::currentDate();
query.prepare("insert into client (id,nom,prenom,genre,adresse,datenaiss,date_enrg) values (:id,:nom,:prenom,:genre,:adresse,TO_DATE(:datenaiss, 'DD/MM/YYYY'),TO_DATE(:date_enrg, 'DD/MM/YYYY'))");
query.bindValue(":id",id);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":genre",genre);
query.bindValue(":adresse",adresse);
query.bindValue(":datenaiss",date_nais);
query.bindValue(":date_enrg",datecurent.toString("dd/MM/yyyy"));
return query.exec();
}
QSqlQueryModel *Client::afficher()
{
QSqlQuery query;
QSqlQueryModel *model=new QSqlQueryModel();
query.prepare(QString("Select * from client"));
query.exec();
model->setQuery(query);
return model;
}

bool Client::supprimer()
{
    QSqlQuery query;
    query.prepare(QString("DELETE from client where id=:id"));
    query.bindValue(":id",id);
    return query.exec();
}
//non crud
bool Client::update()
{
    QSqlQuery query;
    query.prepare(QString("update client set nom=:nom,prenom=:prenom,genre=:genre,adresse=:adresse,datenaiss=TO_DATE(:datenaiss, 'DD/MM/YYYY') where id=:id"));
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":genre",genre);
    query.bindValue(":adresse",adresse);
    query.bindValue(":datenaiss",date_nais);
    return query.exec();
}
QSqlQueryModel * Client::trie(QString mode)
{
    QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel();
    if (mode=="Decroissant")
        query.prepare(QString("select * from client order by DATENAISS desc"));
    else
     query.prepare(QString("select * from client order by DATENAISS"));
    query.exec();
    model->setQuery(query);
    return model;


}
QSqlQueryModel * Client::recherche()
{
    QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel();
    query.prepare(QString("select * from client where id=:id"));
    query.bindValue(0,id);
    query.exec();
    model->setQuery(query);
    return model;
}
QString  Client::recherchee()
{
    QSqlQuery query;
    query.prepare(QString("select id from client where id=:id"));
    query.bindValue(0,id);
    query.exec();
    query.next();
    return query.value(0).toString();
}

QSqlQueryModel * Client::autoremplisage()
{
    QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel();
    query.prepare(QString("select id from client"));
    query.exec();
    model->setQuery(query);
    return model;
}
bool Client::supprimer_innactif()
{
    QSqlQuery query;
    query.prepare(QString("delete from client where DATE_ENRG < TO_DATE(:date_enrg, 'DD/MM/YYYY')"));
    query.bindValue(0,date_enrg);
    return query.exec();



}
QSqlQuery Client::chercher()
{

    QSqlQuery query;
    query.prepare(QString("select * from client where date_enrg < TO_DATE(:date_enrg, 'DD/MM/YYYY')"));
    query.bindValue(0,date_enrg);
     query.exec();
     return query;

}
int Client::calculenfant()
{
    QMessageBox box;
    QString curentdate = QDate::currentDate().toString("dd/MM/yyyy");
    QString year = QDate::currentDate().toString("yyyy");
            int a=year.toInt()-18;
            curentdate.resize(6);
            curentdate+=QString::number(a);
    QSqlQuery query;
    query.prepare(QString("select count(*) from client where datenaiss > TO_DATE(:date,'DD/MM/YYYY')"));
    query.bindValue(0,curentdate);
     query.exec();
     query.next();
     return query.value(0).toInt();

}

int Client::calculpersonneage()
{
    QMessageBox box;
    QString curentdate = QDate::currentDate().toString("dd/MM/yyyy");
    QString year = QDate::currentDate().toString("yyyy");
            int a=year.toInt()-75;
            curentdate.resize(6);
            curentdate+=QString::number(a);
    QSqlQuery query;
    query.prepare(QString("select count(*) from client where datenaiss < TO_DATE(:date,'DD/MM/YYYY')"));
    query.bindValue(0,curentdate);

     query.exec();
     query.next();


     return query.value(0).toInt();

}

int Client::calculadulte()
{
    QMessageBox box;
    QString dateage = QDate::currentDate().toString("dd/MM/yyyy");
    QString year = QDate::currentDate().toString("yyyy");
            int a=year.toInt()-75;
            dateage.resize(6);
            dateage+=QString::number(a);

            QString datenfant = QDate::currentDate().toString("dd/MM/yyyy");
            QString year2 = QDate::currentDate().toString("yyyy");
            int a2=year2.toInt()-18;
            datenfant.resize(6);
            datenfant+=QString::number(a2);

    QSqlQuery query;
    query.prepare(QString("select count(*) from client where datenaiss between TO_DATE(:date2,'DD/MM/YYYY') and TO_DATE(:date1,'DD/MM/YYYY')"));
    query.bindValue(":date1",datenfant);
      query.bindValue(":date2",dateage);

     query.exec();
     query.next();
     return query.value(0).toInt();

}

int Client::homme(QDate datenomm)
{


   QString datenom=datenomm.toString("dd/MM/yyyy");
      QSqlQuery query;
      query.prepare(QString("select count(*) from client where to_date(date_enrg,'DD/MM/YY') =to_date(:date,'DD/MM/YYYY') and genre='Homme' "));
              query.bindValue(":date",datenom);
              query.exec();
    query.next();
    return query.value(0).toInt();

}
int Client::femme(QDate datenomm)
{

   QString datenom=datenomm.toString("dd/MM/yyyy");
      QSqlQuery query;
      query.prepare(QString("select count(*) from client where to_date(date_enrg,'DD/MM/YY') = TO_DATE(:date,'DD/MM/YYYY') and genre='Femme' "));
              query.bindValue(":date",datenom);
              query.exec();
    query.next();



    return query.value(0).toInt();

}
bool Client::carte_mag()
{

    QSqlQuery query;
    query.prepare(QString("update client set CARTE_MAG_ENTRÉ=CARTE_MAG_ENTRÉ+1 where id=:id"));
    query.bindValue(":id",id);
    return query.exec();
}
