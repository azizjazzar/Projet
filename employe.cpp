#include "employe.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
employe::employe()
{

}

employe::employe(QString nom,QString prenom,QDate date,QString CIN,int num,QString Email,QString role,QString login,QString password)
{
    this->nom=nom;
    this->prenom=prenom;
    this->date=date;
    this->CIN=CIN;
    this->num=num;
    this->Email=Email;
    this->role=role;
    this->login=login;
    this->password=password;
}

bool employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO employe(CIN,nom,prenom,num,email,login,mot_de_passe,date_de_naissance,role)""values(:CIN,:nom,:prenom,:num,:email,:login,:mot_de_passe,:date,:role)");
    query.bindValue(":date",date);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",Email);
    query.bindValue(":login",login);
    query.bindValue(":mot_de_passe",password);
    query.bindValue(":role",role);
    query.bindValue(":CIN",CIN);
    query.bindValue(":num",num);
    return  query.exec();

}

QSqlQueryModel * employe::affichier()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe");
    return model;

}

bool employe::supprimer(QString a)
{
    QSqlQuery query;
    if(a!="")
    {
        query.prepare("DELETE FROM employe where CIN= :CIN");
        query.bindValue(":CIN",a);
    }
    return  query.exec();
}

bool employe::modifier(string choice, QString val,QString where)
{
    QSqlQuery query;
    if(choice=="Nom")
    {
       query.prepare("UPDATE employe SET nom= :nom where cin= :cin");
       query.bindValue(":nom",val);
       query.bindValue(":cin",where);
    }
    else if(choice=="Prenom")
    {
       query.prepare("UPDATE employe SET Prenom= :Prenom where cin= :cin");
       query.bindValue(":Prenom",val);
       query.bindValue(":cin",where);
    }
    else if(choice=="CIN")
    {
       query.prepare("UPDATE employe SET CIN= :CIN where cin= :cin");
       query.bindValue(":CIN",val);
       query.bindValue(":cin",where);
    }
    else if(choice=="Role")
    {
       query.prepare("UPDATE employe SET Role= :Role where cin= :cin");
       query.bindValue(":Role",val);
       query.bindValue(":cin",where);
    }
    else if(choice=="Email")
    {
       query.prepare("UPDATE employe SET Email= :Email where cin= :cin");
       query.bindValue(":Email",val);
       query.bindValue(":cin",where);
    }
    else if(choice=="Telephone")
    {
       query.prepare("UPDATE employe SET num= :Telephone where cin= :cin");
       query.bindValue(":Telephone",val.toInt());
       query.bindValue(":cin",where);
    }
    return  query.exec();
}
