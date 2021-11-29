#include "employe.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QtCharts>
employe::employe()
{

}

employe::employe(QString a)
{
    CIN=a;
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

bool employe::access(QString a, QString b)
{
    QSqlQuery query,query2;
    query2.prepare("SELECT * FROM employe");
    query.prepare("SELECT * FROM employe WHERE login=? AND mot_de_passe=? AND role=?");
    query.addBindValue(a);
    query.addBindValue(b);
    QString s("Responsable resourse humaine");
    query.addBindValue(s);
    query.exec();
    query2.exec();
    account(a,b);
    return ((query.next())||(!(query2.next())));
}

bool employe::account(QString a, QString b)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM employe WHERE login=? AND mot_de_passe=?");
    query.addBindValue(a);
    query.addBindValue(b);
    if(query.exec()&&query.next())
    {

            QSqlQueryModel model;
            model.setQuery(query);
            CIN=model.data(model.index(0,0)).toString();
            nom=model.data(model.index(0,1)).toString();
            prenom=model.data(model.index(0,2)).toString();
            num=model.data(model.index(0,3)).toInt();
            Email=model.data(model.index(0,4)).toString();
            login=model.data(model.index(0,5)).toString();
            password=model.data(model.index(0,6)).toString();
            date=model.data(model.index(0,7)).toDate();
            role=model.data(model.index(0,8)).toString();
            return true;

    }
    return false;
}

QSqlQueryModel * employe::rechercher(QString a,string b)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    if(b=="rechercher par CIN")
    {
        query.prepare("SELECT * FROM employe WHERE CIN= :cin");
        query.bindValue(":cin",a);
    }
    else if(b=="rechercher par nom")
    {
        query.prepare("SELECT * FROM employe WHERE nom= :nom");
        query.bindValue(":nom",a);
    }
    else if(b=="rechercher par prenom")
    {
        query.prepare("SELECT * FROM employe WHERE prenom= :prenom");
        query.bindValue(":prenom",a);
    }
    else if(b=="rechercher par role")
    {
        query.prepare("SELECT * FROM employe WHERE role= :role");
        query.bindValue(":role",a);
    }
    if(query.exec())
        model->setQuery(query);
    return model;
}

QSqlQueryModel * employe::tri(string a,string b)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    if(a=="par ordre alphebetique de prenom")
    {
        if(b=="croissant")
            query.prepare("SELECT * FROM employe order by prenom ");
        else
            query.prepare("SELECT * FROM employe order by prenom DESC");
    }
    else if(a=="par ordre alphebetique de nom")
    {
        if(b=="croissant")
            query.prepare("SELECT * FROM employe order by nom ");
        else
            query.prepare("SELECT * FROM employe order by nom DESC");
    }
    else if(a=="par ordre alphebetique de login")
    {
        if(b=="croissant")
            query.prepare("SELECT * FROM employe order by login ");
        else
            query.prepare("SELECT * FROM employe order by login DESC");
    }
    else if(a=="par ordre alphebetique de email")
    {
        if(b=="croissant")
            query.prepare("SELECT * FROM employe order by email ");
        else
            query.prepare("SELECT * FROM employe order by email DESC");
    }
    if(query.exec())
        model->setQuery(query);
    else return NULL;
    return model;

}

QSqlQueryModel * employe::emploi()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT voyage.depart,voyage.heure_depart,voyage.heure_arrive,voyage.destination,voyage.matricule FROM voyage WHERE cin_chaufeur= :cin AND (extract(year from heure_arrive))= :year  AND (extract(month from heure_arrive))= :month AND (extract(day from heure_arrive))>= :day AND etat= :etat order by heure_depart");
    QDate d=d.currentDate();
    int year,month,day;
    d.getDate(&year,&month,&day);
    query.bindValue(":year",year);
    query.bindValue(":month",month);
    query.bindValue(":day",day);
    query.bindValue(":cin",CIN);
    query.bindValue(":etat","plannifier");
    if(query.exec())
        model->setQuery(query);
    return model;
}

float employe::chauffeur()
{
    QSqlQuery query;
    QSqlQueryModel model;
    query.prepare("SELECT COUNT (role) FROM employe WHERE role = :role");
    query.bindValue(":role","chauffeur");
    query.exec();
    model.setQuery(query);
    float a=model.data(model.index(0,0)).toFloat();
    query.prepare("SELECT COUNT (role) FROM employe");
    query.exec();
    model.setQuery(query);
    float b=model.data(model.index(0,0)).toFloat();
    return a/b;
}

float employe::RRH()
{
    QSqlQuery query;
    QSqlQueryModel model;
    query.prepare("SELECT COUNT (role) FROM employe WHERE role = :role");
    query.bindValue(":role","Responsable resourse humaine");
    query.exec();
    model.setQuery(query);
    float a=model.data(model.index(0,0)).toFloat();
    query.prepare("SELECT COUNT (role) FROM employe");
    query.exec();
    model.setQuery(query);
    float b=model.data(model.index(0,0)).toFloat();
    return a/b;
}

float employe::other()
{
    QSqlQuery query;
    QSqlQueryModel model;
    query.prepare("SELECT COUNT (role) FROM employe WHERE role != :role AND role != :role2");
    query.bindValue(":role","Responsable resourse humaine");
    query.bindValue(":role2","chauffeur");
    query.exec();
    model.setQuery(query);
    float a=model.data(model.index(0,0)).toFloat();
    query.prepare("SELECT COUNT (role) FROM employe");
    query.exec();
    model.setQuery(query);
    float b=model.data(model.index(0,0)).toFloat();
    return a/b;
}
QString employe::get_cin()
{
    return CIN;
}

QString employe::get_nom()
{
    return nom;
}
QString employe::get_prenom()
{
    return prenom;
}
int employe::get_num()
{
    return num;
}
QDate employe::get_date()
{
    return date;
}
QString employe::get_role()
{
    return role;
}
QString employe::get_email()
{
    return Email;
}
QString employe::get_login()
{
    return login;
}
QString employe::get_password()
{
    return password;
}

