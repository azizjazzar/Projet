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
    employe();
    employe(QString nom,QString prenom,QDate date,QString CIN,int num,QString Email,QString role,QString login,QString password);
    /*int get_cin();
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
    void set_date(QDate a);*/
    bool ajouter();
    QSqlQueryModel * affichier();
    bool supprimer(QString a);
    bool modifier(string choice,QString val,QString where);
    bool access(QString a,QString b);
private:
    QString nom,prenom,Email,login,password,CIN,role;
    int num;
    QDate date;
};

#endif // EMPLOYE_H
