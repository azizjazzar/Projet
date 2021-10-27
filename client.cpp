#include "client.h"
#include "connection.h"
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
QSqlQuery query(QSqlDatabase::database("test-db"));
query.prepare("insert into client (id,nom,prenom,genre,adresse,datenaiss) values (:id,:nom,:prenom,:genre,:adresse,:datenaiss)");
query.bindValue(":id",id);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":genre",genre);
query.bindValue(":adresse",adresse);
query.bindValue(":datenaiss","01-01-2000");
return query.exec();
}

