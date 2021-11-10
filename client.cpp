#include "client.h"
#include "connection.h"
#include <QMessageBox>

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
//crud
bool Client::ajouter()
{
QSqlQuery query;
query.prepare("insert into client (id,nom,prenom,genre,adresse,datenaiss) values (:id,:nom,:prenom,:genre,:adresse,TO_DATE(:datenaiss, 'DD/MM/YYYY'))");
query.bindValue(":id",id);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":genre",genre);
query.bindValue(":adresse",adresse);
query.bindValue(":datenaiss",date_nais);
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
