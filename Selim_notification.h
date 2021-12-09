#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>
#include "Selim_mainwindow.h"

class ActiveAb
{
private:
    QString cin;
    QString type;
    QString DateStart;
    QString DateFin;


public:
    ActiveAb();
    ActiveAb(QString,QString,QString,QString);
    void SetDateStart(QString);
    QDate GetDateFin(QString);
    void create_notifs(QString,QString);
    bool renouv(Ui::Selim_MainWindow *ui);
    QSqlQueryModel * afficher_notifs();
};

#endif // NOTIFICATION_H
