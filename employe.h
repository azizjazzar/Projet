#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
using namespace std;
#include <string>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include "mainwindow.h"
class employe
{
public:
    employe(QString a);
    employe();
    employe(QString nom,QString prenom,QDate date,QString CIN,int num,QString Email,QString role,QString login,QString password);
    QString get_cin();
    int get_num();
    QString get_nom();
    QString get_prenom();
    QString get_email();
    QString get_login();
    QString get_password();
    QString get_role();
    QDate get_date();
    void set_cin(int a);
    void set_num(int a);
    void set_nom(string a);
    void set_prenom(QString a);
    void set_email(QString a);
    void set_login(QString a);
    void set_password(QString a);
    void set_role(QString a);
    void set_date(QDate a);
    bool ajouter();
    QSqlQueryModel * affichier();
    QSqlQueryModel * rechercher(QString a, string b);
    bool supprimer(QString a);
    bool modifier(string choice,QString val,QString where);
    bool access(QString a,QString b);
    bool account(QString a,QString b);
    QSqlQueryModel * tri(string a,string b);
    QSqlQueryModel * emploi();
    float RRH();
    float chauffeur();
    float other();
private:
    QString nom,prenom,Email,login,password,CIN,role;
    int num;
    QDate date;
};

#endif // EMPLOYE_H
